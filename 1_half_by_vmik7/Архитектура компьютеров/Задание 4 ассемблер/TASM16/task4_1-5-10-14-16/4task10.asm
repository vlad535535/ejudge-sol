.MODEL TINY
.STACK 100h
.DATA
	arr dw 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
	n dw 20
.CODE
	mov ax,@Data
	mov ds,ax
	
	mov bx,n
	add bx,n
	sub bx,2
MAS:	push arr[bx]
	call print_num
	sub bx,2
	dec n
	cmp n,0
	jg MAS

	MOV AH,10h
	INT 16h
	MOV AX,4C00h
	INT 21h

print_num proc	
	push bx
	push bp
	mov bp,sp
	MOV AX,[bp+6]
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
	MOV dl," "
	INT 21h
	pop bp
	pop bx
	ret
print_num endp
END
