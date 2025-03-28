global ft_strcpy
section .text
ft_strcpy:
	xor		rcx, rcx
.loop:
	mov		al, byte [rsi + rcx]
	mov		byte [rdi + rcx], al
	cmp		al, 0
	je		.done
	inc		rcx
	jmp		.loop
.done:
	mov		rax, rdi
	ret
