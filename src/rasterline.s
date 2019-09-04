.export _rasterirq
.export _stoprasterirq 

STARTBLUE     = $00                ;Wo beginnt blau
STARTGREEN    = $DE                ;           grün

_rasterirq: 

 sei                                ;Interrupts sperren
 
 lda #<rasterIrq                    ;unsere Interrupt-Routine
 sta $0314                          ;in den IRQ-Vector eingtragen
 lda #>rasterIrq                    ;auch das MSB
 sta $0315
 
 lda #STARTBLUE                     ;Bei STARTBLUE soll ein
 sta $d012                          ;Raster-IRQ ausgelöst werden
 
 lda $d011                          ;Zur Sicherheit auch noch
 and #%01111111                     ;das höhste Bit für den
 sta $d011                          ;gewünschten Raster-IRQ löschen 
 
 lda $d01a                          ;IRQs vom
 ora #%00000001                     ;VIC-II aktivieren
 sta $d01a
 cli                                ;Interrupts wieder erlauben
 rts                                ;zurück 
 
 
;*=$1000
;*** unsere eigene Interrupt-Routine
rasterIrq:
 lda $d019 
 bmi doRasterIrq                    ;wenn ja -> Raster IRQ
 lda $dc0d                          ;sonst, CIA-IRQ bestätigen  
 cli                                ;IRQs erlauben
 jmp $ea31                          ;und zur ROM-Routine springen
 jmp rasterIrqExit
 
;*** hier beginnt die Raster-Interrupt-Funktion
doRasterIrq:                        
 sta $d019                          ;IRQ bestätigen
 
 lda $d012                          ;aktuelle Rasterzeile in den Akku
 bne doGreen                        ;wenn ungleich 0 'rot' prüfen
 lda #$0E                           ;sonst 'hellblau' in den Akku
 sta $d020                          ;und als Rahmen-
 sta $d021                          ;sowie Hintergrundfarbe setzen
 
 lda #STARTGREEN                    ;Rasterzeile für 'grün'
 sta $d012                          ;festlegen
 jmp rasterIrqExit                  ;und raus
 
doGreen:
 lda #$05                           ;setze grün
 sta $d020                          ;als Rahmen-
 sta $d021                          ;und Hintergrundfarbe
 lda #STARTBLUE                     ;Rasterzeile für blau (wir beginnen
 sta $d012                          ;von vorne) festlegen
 
rasterIrqExit:
 pla                                ;Y vom Stack
 tay
 pla                                ;X vom Stack
 tax
 pla                                ;Akku vom Stack
 rti                                ;Interrupt verlassen

_stoprasterirq:
 lda $d01a                          ;IRQs vom
 and #%11111110                     ;VIC-II deaktivieren
 sta $d01a
 rts
