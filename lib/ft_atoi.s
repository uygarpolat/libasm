global ft_atoi

section	.bss
sign:	resq 1
nbr:	resq 1

section	.text

ft_isspace:
	cmp		dil, ' '	; dil is the lower 8 bits of RDI
	je		.isspace

	cmp		dil, 9
	jl		.notspace
	cmp		dil, 13
	jg		.notspace

.isspace:
	mov		eax, 1
	ret

.notspace:
	xor		eax, eax
	ret

ft_atoi:
	mov		qword [rel sign], 1
	mov		qword [rel nbr], 0
	mov		rsi, rdi

.loop:
	; register order: rdi, rsi, rdx
	movzx	rdi, byte [rsi]
	call	ft_isspace
	cmp		eax, 0
	je		.next
	inc		rsi
	jmp		.loop

.next:
	movzx	rdi, byte [rsi]
	cmp		rdi, '-'
	je		.flipsign
	cmp		rdi, '+'
	je		.increment
	jmp		.loop2

.flipsign:
	neg		qword [rel sign]
	jmp		.increment
.increment:
	inc		rsi

.loop2:
	movzx	rdi, byte [rsi]
	cmp		rdi, '0'
	jl		.end
	cmp		rdi, '9'
	jg		.end
	mov		rax, qword [rel nbr]        ; load current value of nbr into rax

	mov		rax, qword [rel nbr]	; load current nbr into rax
	mov		rcx, rax				; save nbr in RCX
	shl		rax, 1					; rax = nbr * 2
	lea		rax, [rax + rcx*8]		; rax = (nbr * 2) + (nbr * 8) = nbr * 10

	sub		rdi, '0'
	add		rax, rdi
	mov		qword [rel nbr], rax

	inc		rsi
	jmp		.loop2

.end:
	mov		rax, qword [rel nbr]  ; load nbr into rax
	imul	rax, qword [rel sign] ; multiply rax by sign (result stored in rax)
	ret
