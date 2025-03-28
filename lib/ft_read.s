global ft_read
extern __errno_location
section .text
ft_read:
    mov		rax, 0
    syscall

    cmp		rax, 0
    jge		.done

    neg		rax
    mov		r10, rax
    call	__errno_location	; __errno_location returns pointer to errno into rax
    mov		dword [rax], r10d	; store error code into errno (as a 32-bit int)
    mov		rax, -1
.done:
	ret
