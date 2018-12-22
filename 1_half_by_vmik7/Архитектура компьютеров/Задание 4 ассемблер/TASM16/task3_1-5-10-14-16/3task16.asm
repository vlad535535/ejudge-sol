.MODEL TINY
.STACK 100h
.DATA
	num db 1,2,3,4,5,6,7
	nam db "Egor$","Andrew$","John$","Sarah$","Bob$","Ivan$","Arny$"
	mark db 4,3,4,5,2,5,5
	n dw 7
	count dw 0
.CODE
	mov ax,@Data
	mov ds,ax
	
	mov cx,n
	xor bx,bx
L:	mov al,mark[bx]
	cmp al,5
	jne LOSER
	inc count
LOSER:	inc bx	
	loop L
	
OUTP:	MOV AX,count
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
