.MODEL TINY
.STACK 100h
.DATA
	a dw 33
	b dw 68
.CODE
	mov ax,@Data
	mov ds,ax
	
	mov ax,a
	mov dx,b
	CMP ax,dx
	JGE OUTP
	MOV a,dx
	MOV b,ax

OUTP:	MOV AX,a
	XOR CX,CX
SAVE:	INC CX
	MOV BL,10
	DIV BL
	ADD AH, '0'
	PUSH AX
	XOR AH, AH
	CMP AX,0
	JNE SAVE

	MOV AX,0200h
PRINT:	POP dx
	MOV dl,dh
	INT 21h
	LOOP PRINT   

	MOV AH,10h
	INT 16h
	MOV AX,4C00h
	INT 21h
END
