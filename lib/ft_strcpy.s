global _ft_strcpy

section __TEXT,__text
_ft_strcpy:
    xor rax, rax
.loop:
    mov al, byte [rsi + rax]
    mov byte [rdi + rax], al
    cmp al, 0
    je .done
    inc rax
    jmp .loop
.done:
    mov rax, rdi
    ret
