.MODEL TINY
.STACK 100h
.DATA
	arr db "0","0","0","0","0","1","1","1","1","1"
	n dw 5
.CODE
START:	mov ax,@Data
	mov ds,ax
	
	xor bx,bx
	mov cx,n
L:	mov al,arr[bx]
	push ax
	call print
	add bx,n
	mov al,arr[bx]
	push ax
	call print
	sub bx,n
	inc bx
	loop L

	MOV AH,10h
	INT 16h
	MOV AX,4C00h
	INT 21h
	
	;define procedure
print proc
	push bp
	mov bp,sp
	mov ax,[bp+4]
	mov dl,al
	mov ah,2
	int 21h
	pop bp
	ret
print endp 
	;end of procedure
END START

