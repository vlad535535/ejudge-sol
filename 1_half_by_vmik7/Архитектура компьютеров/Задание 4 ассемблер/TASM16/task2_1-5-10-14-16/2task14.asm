.MODEL TINY
.STACK 100h
.DATA
	a db 21
	b db 10
	r dw 0
	over db "OF=1$"
	nover db "OF=0$"
.CODE
	mov ax,@Data
	mov ds,ax
	xor ax,ax
	
	cmp a,0
	je nov
	cmp b,0
	je nov
	
	mov al,a
	mul b
	jo ov
	
NOV:	mov dx,offset nover
	mov ah,9h
	int 21h
	mov ah,10h
	int 16h
	mov ah,4ch
	int 21h
	
OV:	mov dx,offset over
	mov ah,9h
	int 21h
	mov ah,10h
	int 16h
	mov ah,4ch
	int 21h
END
