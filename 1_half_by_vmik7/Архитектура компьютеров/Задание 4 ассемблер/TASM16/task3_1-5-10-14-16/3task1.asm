.MODEL TINY
.STACK 100h
.DATA
	arr db "0","0","0","0","0","1","1","1","1","1"
	n dw 5
.CODE
	mov ax,@Data
	mov ds,ax
	
	xor bx,bx
	mov cx,n
	mov ah,2
L:	mov dl,arr[bx]
	int 21h
	add bx,n
	mov dl,arr[bx]
	int 21h
	sub bx,n
	inc bx
	loop L

	MOV AH,10h
	INT 16h
	MOV AX,4C00h
	INT 21h
END
