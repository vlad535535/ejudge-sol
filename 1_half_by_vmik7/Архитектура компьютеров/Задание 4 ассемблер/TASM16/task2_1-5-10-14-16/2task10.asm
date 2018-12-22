.MODEL TINY
.STACK 100h
.DATA
	w dw 12345
	result dw 0
.CODE
	mov ax,@Data
	mov ds,ax
	
	mov ax,w
	mov bx,10
COUNTER:	div bx
	xor dx,dx
	inc result
	cmp ax,0
	jne COUNTER
	
	mov ah,4ch
	int 21h
END
