	.file	"fork.c"
	.text
	.section	.rodata
.LC0:
	.string	"The fork can not be created"
.LC1:
	.string	"This is the child process "
	.align 8
.LC2:
	.string	"The process id of child process is %d\n"
.LC3:
	.string	"This parent process id is %d\n"
	.align 8
.LC4:
	.string	"This is the parent process this process id is %d\n"
.LC5:
	.string	"\n cpid returned is (%d)\n"
.LC6:
	.string	"\n Status is (%d)\n"
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
	subq	$16, %rsp
	movl	$0, -12(%rbp)
	call	fork@PLT
	movl	%eax, -8(%rbp)
	cmpl	$-1, -8(%rbp)
	jne	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$-1, %edi
	call	exit@PLT
.L2:
	cmpl	$0, -8(%rbp)
	jne	.L3
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	getppid@PLT
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %edi
	call	sleep@PLT
	movl	$3, %edi
	call	exit@PLT
.L3:
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	wait@PLT
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
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
