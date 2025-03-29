global ft_strdup
extern __errno_location
extern ft_strlen
extern ft_strcpy
extern malloc
section .text
ft_strdup:
	xor		rax, rax
	push	rdi

    call	ft_strlen
	inc		rax

    mov		rdi, rax
    call	malloc
    cmp		rax, 0
    je		.error

	pop		rsi
	mov		rdi, rax
	call	ft_strcpy
	ret

.error
	pop		rsi
    mov		r10, 12
    call	__errno_location
    mov		dword [rax], r10d
	xor		rax, rax
	ret
