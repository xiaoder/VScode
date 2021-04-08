DATA SEGMENT
	X    DW -13
	Y    DW 30
	Z    DW 24
	W    DW 50
	A    DW ?,?
DATA ENDS
CODE SEGMENT
	      ASSUME CS:CODE,DS:DATA
	START:
	      MOV    AX,DATA
	      MOV    DS,AX
	
	      MOV    AX,Y
	      IMUL   Z
	      MOV    CX,AX
	      MOV    BX,DX
	      SUB    CX,100
	      SBB    BX,0
	      MOV    AX ,X
	      CWD                   	;因为Y*Z出来是32位，AX也要扩成32位才能相加 CWD,字转换为双字，表示将AX中的符号位扩张到DX
	      ADD    AX,CX
	      ADC    DX,BX
	      IDIV   W              	;AX存商，DX存小数
	      MOV    A,AX
	      MOV    A+2,DX
	      MOV    AH,4CH
	      INT    21H
CODE ENDS
	END START
