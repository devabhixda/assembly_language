section .bss
	buffer resb 64
	buffer_len resq 1

section .text
global _start
_start:
	mov rax, 0
	mov rdi, 0
	mov rsi, buffer
	mov rdx,64
	syscall

	mov [buffer_len],rax

	mov rax,1
	mov rdi,1
	mov rsi,buffer
	mov rdx, [buffer_len]
	syscall

	mov rax, 60 ;Exit
	mov rdi, 0
	syscall
