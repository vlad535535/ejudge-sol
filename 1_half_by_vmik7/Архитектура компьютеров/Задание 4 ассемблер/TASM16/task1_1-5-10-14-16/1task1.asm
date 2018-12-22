.MODEL TINY
.STACK 100h
.DATA
	w dd 11112222h
.CODE
	mov ax,@Data
	mov ds,ax
	
	push word ptr [w]
	push word ptr [w+2]
		
	pop word ptr [w]
	pop word ptr [w+2]
	
	mov ah,4ch              ; функция DOS завершения программы
	int 21h                 ; завершить программу
END
