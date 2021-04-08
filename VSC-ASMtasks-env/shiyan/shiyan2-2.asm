DATA SEGMENT
	X    DW 1122H,3344H
	Y    DW 5566H,7788H
	Z    DW 1122H,3344H
	W    DW ?,?
DATA ENDS
 
CODE SEGMENT
	      ASSUME CS:CODE,DS:DATA
	START:
	      MOV    AX,DATA
	      MOV    DS,AX
	
	      MOV    AX,Y
	      MOV    DX,Y+2
	      SUB    AX,Z
	      SBB    DX,Z+2
	      ADD    AX,X 
	      ADC    DX,X+2
	      MOV    W,AX
	      MOV    W+2,DX
	      MOV    AH,4CH
	      INT    21H
 
CODE ENDS
	END START
