global ft_memcpy
section .text
ft_memcpy:
	test	rdx, rdx
	jz		.done

	xor		rcx, rcx
.loop:
	mov		al, byte [rsi + rcx]
	mov		byte [rdi + rcx], al
	inc		rcx
	cmp		rcx, rdx
	jne		.loop
.done:
	mov		rax, rdi
	ret
