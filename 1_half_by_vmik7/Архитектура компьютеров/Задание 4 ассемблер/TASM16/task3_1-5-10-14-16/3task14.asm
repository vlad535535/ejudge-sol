.MODEL TINY
.STACK 100h
.DATA
	arr dw 10,9,8,7,11,6,5,4,3,2,1
	n db 11
.CODE
	mov ax,@Data
	mov ds,ax
	
	mov al,2
	mov dl, n
	mul dl
	sub ax,2
	i dw 0
LOOP1:	xor bx,bx
	LOOP2:	mov dx,arr[bx]
		add bx,2
		cmp dx,arr[bx]
		jle OK
		xchg dx,arr[bx]
		mov arr[bx-2],dx
		mov dl,n
		add dl,n
		sub dx,i
		sub dx,2
	OK:	cmp bx,dx
		jl LOOP2
	
	add i,2
	cmp i,ax
	jl LOOP1
	
	mov bx,0
MAS:	mov ax,arr[bx]
	XOR CX,CX
SAVE:	INC CX
	MOV dl,10
	DIV dl
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
	
	add bx,2
	dec n
	cmp n,0
	jg MAS

	MOV AH,10h
	INT 16h
	MOV AX,4C00h
	INT 21h
END
