
.data
msgCaption db "WE ARENT ENEMIES RIGHT?", 0


.code
ALIGN 16

EXTERN GetMessageBoxType : PROC
EXTERN MessageBoxA	: PROC

asm_func PROC
	
	; RCX = ; uh
	sub		rsp, 28h ;	shadow stack
	mov [rsp], rcx
	
	call GetMessageBoxType

	mov		r9, rax
	mov		r8,	 [rsp]	
	lea		rdx, [msgCaption]
	
	xor		ecx, ecx

	call	MessageBoxA

	add		rsp, 28h ;	restore shadowstack
	mov		rax, 39
; ------------------------------------------------------------------------------ END
	
	ret
asm_func ENDP




END
; ------------------------------------------------------------------------------END OF END