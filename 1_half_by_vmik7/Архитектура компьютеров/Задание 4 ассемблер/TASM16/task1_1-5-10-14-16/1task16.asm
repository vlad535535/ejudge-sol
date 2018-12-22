.model tiny
.stack 100h
.data
	x dd 12345
	y dw 100
	m dw ?
.code
START: 	MOV AX,@data
		MOV DS,AX
		XOR AX,AX

		MOV AX,word ptr [x]
		MOV DX,word ptr [x+2]
		DIV y
		MOV m,DX
		
		MOV AX,4C00h
		INT 21h
END START