.MODEL SMALL
.STACK 100h
.DATA
    Message  DB 'Hello123456!$'
.CODE
	mov ax,@Data
	mov ds,ax          		; установить регистр DS таким
							; образом, чтобы он указывал
							; на сегмент данных
	mov ah,9                ; функция DOS вывода строки
	mov dx,OFFSET Message   ; ссылка на сообщение "Привет!"
	int 21h                 ; вывести "Привет!" на экран
	
	mov  ah,10h             ; Поместить значение 10h в регистр AH
	int  16h                ; Вызвать подпрограмму ожидания нажатия клавиши
	mov ah,4ch              ; функция DOS завершения программы
	int 21h                 ; завершить программу
END
