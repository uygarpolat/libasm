global ft_bzero
extern ft_memset
section .text
ft_bzero:
    mov     rdx, rsi
    mov     rsi, 0
    call    ft_memset
    ret
