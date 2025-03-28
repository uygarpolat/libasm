global ft_strcmp
section .text
ft_strcmp:
.loop:
	mov		al, byte [rdi]
	mov		bl, byte [rsi]
	cmp		al, bl
	jne		.done
	cmp		al, 0
	je		.equal
	inc		rdi
	inc		rsi
	jmp		.loop

.done:
	movzx	eax, al
	movzx	ebx, bl
	sub		eax, ebx
	ret

.equal:
	xor		eax, eax
	ret
