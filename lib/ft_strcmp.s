bits 64
default rel
global _ft_strcmp

section __TEXT,__text
_ft_strcmp:
.loop:
	mov		al, byte [rdi]
	mov		bl, byte [rsi]
	cmp		al, bl
	jne		.done
	test	al, 0
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
