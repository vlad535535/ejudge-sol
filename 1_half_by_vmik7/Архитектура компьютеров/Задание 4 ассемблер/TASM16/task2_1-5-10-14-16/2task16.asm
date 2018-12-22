.MODEL TINY
.STACK 100h
.DATA
	a dw 2
	b dw 3
	c dw 5
	yes db "yes$"
	no db "no$"
.CODE
	mov ax,@Data
	mov ds,ax
	
	mov ax, b
	add ax, c
	cmp ax, a
	jle N
	
	mov ax, a
	add ax, c
	cmp ax, b
	jle N
	
	mov ax, a
	add ax, b
	cmp ax, c
	jle N
	
Y:	mov dx,offset yes
	mov ah,9h
	int 21h
	mov ah,10h
	int 16h
	mov ah,4ch
	int 21h
	
N:	mov dx,offset no
	mov ah,9h
	int 21h
	mov ah,10h
	int 16h
	mov ah,4ch
	int 21h
END
