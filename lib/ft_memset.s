global ft_memset
section .text
ft_memset:
	test	rdx, rdx
	jz		.done

    mov     al, sil ; write the lower 8 bits of rsi into al
	xor		rcx, rcx
.loop:
	mov		byte [rdi + rcx], al
	inc		rcx
	cmp		rcx, rdx
	jne		.loop
.done:
	mov		rax, rdi
	ret
