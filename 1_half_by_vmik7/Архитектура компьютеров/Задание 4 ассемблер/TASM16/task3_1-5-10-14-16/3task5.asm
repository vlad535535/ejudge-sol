.MODEL TINY
.STACK 100h
.DATA
	arr dw 1,2,3,4,575,6,7,8,9,8,7,6,5,4,3,2,1
	n dw 17
	max dw 0
.CODE
	mov ax,@Data
	mov ds,ax
	
	xor bx,bx
	mov cx,n
MAS:	mov ax,arr[bx]
	cmp ax,max
	jle CON
	mov max,ax
CON:	add bx,2
	loop MAS
	
OUTP:	MOV AX,max
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
