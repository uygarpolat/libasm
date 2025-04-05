global ft_strchr
section .text
ft_strchr:
	mov		al, sil
.loop:
	mov		bl, byte [rdi]
	cmp		bl, al
	je		.found
	test	bl, bl
	je		.notfound
	inc		rdi
	jmp		.loop
.found:
	mov		rax, rdi
	ret
.notfound:
	xor		rax, rax
	ret
