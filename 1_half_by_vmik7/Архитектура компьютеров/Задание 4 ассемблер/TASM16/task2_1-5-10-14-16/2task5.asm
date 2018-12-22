.MODEL TINY
.STACK 100h
.DATA
	a dw 2
	n dw 12
	r dd ?
.CODE
	mov ax,@Data
	mov ds,ax
	
	mov ax,1
	mov cx,n
POWER:	mul a
	loop POWER
	
	mov word ptr [r+2],dx
	mov word ptr [r],ax
	
	mov ah,4ch
	int 21h
END
