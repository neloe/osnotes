	.file	"simple.c"
# GNU C17 (Ubuntu 11.2.0-19ubuntu1) version 11.2.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.2.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -O0 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.section	.rodata
.LC0:
	.string	"%d "
.LC1:
	.string	""
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# simple.c:5:     for (int i=10; i>0; i--)
	movl	$10, -4(%rbp)	#, i
# simple.c:5:     for (int i=10; i>0; i--)
	jmp	.L2	#
.L3:
# simple.c:6: 	printf("%d ", i);
	movl	-4(%rbp), %eax	# i, tmp84
	movl	%eax, %esi	# tmp84,
	leaq	.LC0(%rip), %rax	#, tmp85
	movq	%rax, %rdi	# tmp85,
	movl	$0, %eax	#,
	call	printf@PLT	#
# simple.c:5:     for (int i=10; i>0; i--)
	subl	$1, -4(%rbp)	#, i
.L2:
# simple.c:5:     for (int i=10; i>0; i--)
	cmpl	$0, -4(%rbp)	#, i
	jg	.L3	#,
# simple.c:7:     puts("");
	leaq	.LC1(%rip), %rax	#, tmp86
	movq	%rax, %rdi	# tmp86,
	call	puts@PLT	#
# simple.c:8:     return 0;
	movl	$0, %eax	#, _6
# simple.c:9: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
