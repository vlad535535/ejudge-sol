.MODEL SMALL
.STACK 100h
.DATA
    Message  DB 'Hello!$'
.CODE
	mov ax,@Data
	mov ds,ax          		
						
	mov ah,9
	mov dx,OFFSET Message
	int 21h
	
	mov  ah,10h
	int  16h
	mov ah,4ch
	int 21h
END
