	.file	"pipe1.c"
	.text
	.section	.rodata
.LC0:
	.string	"pipe error"
.LC1:
	.string	"Error in fork creation\n"
.LC2:
	.string	"Parent close write end"
	.align 8
.LC3:
	.string	"Data received in child process is %s\n"
	.align 8
.LC4:
	.string	"Sending user input string to child process %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	%edi, -84(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	pipe@PLT
	cmpl	$-1, %eax
	jne	.L2
	leaq	.LC0(%rip), %rdi
	call	perror@PLT
	movl	$1, %edi
	call	exit@PLT
.L2:
	call	fork@PLT
	cmpl	$-1, %eax
	je	.L3
	testl	%eax, %eax
	je	.L4
	jmp	.L15
.L3:
	leaq	.LC1(%rip), %rdi
	call	perror@PLT
	movl	$-1, %edi
	call	exit@PLT
.L4:
	movl	-68(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	cmpl	$-1, %eax
	jne	.L6
	movl	$-1, %edi
	call	exit@PLT
.L6:
	movb	$0, -64(%rbp)
	movl	-72(%rbp), %eax
	leaq	-64(%rbp), %rcx
	movl	$50, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movl	%eax, -76(%rbp)
	cmpl	$-1, -76(%rbp)
	jne	.L7
	movl	$-1, %edi
	call	exit@PLT
.L7:
	cmpl	$0, -76(%rbp)
	jne	.L8
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	nop
	movl	-68(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	cmpl	$-1, %eax
	jne	.L17
	jmp	.L16
.L8:
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L16:
	movl	$-1, %edi
	call	exit@PLT
.L15:
	movl	-72(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	cmpl	$-1, %eax
	jne	.L12
	movl	$-1, %edi
	call	exit@PLT
.L12:
	movq	-96(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-96(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rdx
	movq	-96(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rcx
	movl	-68(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write@PLT
	movl	$2, %edi
	call	sleep@PLT
	movl	-68(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	cmpl	$-1, %eax
	jne	.L13
	movl	$-1, %edi
	call	exit@PLT
.L13:
	movl	$0, %edi
	call	wait@PLT
	movl	$0, %edi
	call	exit@PLT
.L17:
	nop
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L14
	call	__stack_chk_fail@PLT
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
