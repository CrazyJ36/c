	.text
	.file	"print-printf.c"
	.globl	main                    // -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   // @main
// %bb.0:
	sub	sp, sp, #32             // =32
	stp	x29, x30, [sp, #16]     // 8-byte Folded Spill
	add	x29, sp, #16            // =16
	adrp	x8, .L.str
	add	x8, x8, :lo12:.L.str
	mov	w0, #0
	stur	w0, [x29, #-4]          // 4-byte Folded Spill
	mov	x0, x8
	bl	printf
	ldur	w9, [x29, #-4]          // 4-byte Folded Reload
	mov	w0, w9
	ldp	x29, x30, [sp, #16]     // 8-byte Folded Reload
	add	sp, sp, #32             // =32
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        // -- End function
	.type	.L.str,@object          // @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"text"
	.size	.L.str, 5


	.ident	"clang version 6.0.0 (tags/RELEASE_600/final)"
	.section	".note.GNU-stack","",@progbits
