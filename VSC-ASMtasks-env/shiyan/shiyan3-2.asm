DATA SEGMENT
	OLDS  DB 5 DUP(?)
	MESS1 DB 'YES$'
	MESS2 DB 'NO$'
DATA ENDS


EXTRA SEGMENT
	NEWS  DB 5 DUP(?)
EXTRA ENDS


CODE SEGMENT
	      ASSUME CS:CODE,DS:DATA,ES:EXTRA
	START:
	      MOV    AX,DATA
	      MOV    DS,AX
	      MOV    CX,5
	      MOV    DI,0

	REST:                                	;输入OLDS
	      MOV    AH,01H
	      INT    21H
	      MOV    OLDS[DI],AL
	      INC    DI
	      LOOP   REST

	      MOV    CX,5
	      MOV    DI,0

	      MOV    DL,0AH
	      MOV    AH,02H
	      INT    21H

	      MOV    AH,02H
	      INT    21H


	REST2:                               	;输入NEWS
	      MOV    AH,01H
	      INT    21H
	      MOV    NEWS[DI],AL
	      INC    DI
	      LOOP   REST2

	      MOV    CX,5
	      MOV    DI,0

	      LEA    SI,OLDS                 	;字符串比较
	      LEA    DI,NEWS
	      CLD
	      REPE   CMPSB

	      MOV    DL,0AH
	      MOV    AH,02H
	      INT    21H
	      JNZ    NO                      	;相同转到YES，不同转到NO
	      JZ     YES

	NO:                                  	;输出NO
	      mov    AH,9
	      MOV    DX,SEG MESS2
	      MOV    DS,DX
	      MOV    DX,OFFSET MESS2
	      INT    21H
	      JMP    GOO

	YES:                                 	;输出YES
	      LEA    DX,MESS1
	      MOV    AH,09H
	      INT    21H

	GOO:  
	      MOV    AH,4CH
	      INT    21H
CODE ENDS
END START
