	ORG 0
MAIN:
	MOV A, #0
	MOV TMOD, #1
	MOV P1, #0xFF
	
NEXT_SECOND:
	MOV R5, #20
	
AGAIN:
	MOV TL0, #176
	MOV TH0, #60
	SETB TR0
	CALL DISPLAY_TIME
	
WAIT:
	JBC TF0, TIMEOUT
	JMP WAIT
	
TIMEOUT:
	DJNZ R5, AGAIN
	INC A
	CJNE A, #10, NEXT_SECOND
	MOV A, #0
	JMP NEXT_SECOND
	
DISPLAY_TIME:
	CLR P1.0
	MOV P2, A	
	RET
	
	end
