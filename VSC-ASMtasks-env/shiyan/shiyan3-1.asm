DATAS SEGMENT
	STRING DB 100 DUP('$')
	LEN    DW ?
	INDEX  DB 100 DUP('$')
DATAS ENDS

CODES SEGMENT
	      ASSUME CS:CODES,DS:DATAS
	START:
	      MOV    AX,DATAS
	      MOV    DS,AX
	      MOV    ES,AX

	      MOV    SI, 0
	INPUT:
	      MOV    AH, 01H
	      INT    21H
	      CMP    AL, 0DH
	      JZ     NEXT
	      MOV    STRING[SI], AL
	      INC    SI
	      JMP    INPUT

	NEXT: MOV    LEN, SI

	      MOV    AL, '&'
	      MOV    CX, LEN
	      MOV    DI, 0
	      MOV    SI, 0
	REST: CMP    AL, STRING[DI]
	      JNZ    NEXT2
	      MOV    STRING[DI], ' '
	      MOV    BX, DI
	      ADD    BL, 31H
	      MOV    INDEX[SI], BL
	      INC    SI
	NEXT2:INC    DI
	      LOOP   REST


	      LEA    DX, STRING
	      MOV    AH, 09H
	      INT    21H

	      MOV    AH, 02H
	      MOV    DL, 0DH
	      INT    21H
	      MOV    DL, 0AH
	      INT    21H

	      LEA    DX, INDEX
	      MOV    AH, 09H
	      INT    21H
    
	      MOV    AH,4CH
	      INT    21H
CODES ENDS
    END START