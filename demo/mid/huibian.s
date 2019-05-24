	.file	"test.c"
	.intel_syntax noprefix
	.section .rdata,"dr"
_L2:
	.ascii "%d\0"
	.align 4
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push ebp
	mov ebp,esp
	and esp, -16
	sub esp,32
	call	___main
	mov eax,0
	mov DWORD PTR[ebp-4],eax
	lea	eax, [ebp-4]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:_L2
	call	_scanf
	mov eax,DWORD PTR [ebp-4]
	mov ebx,1
	add eax,ebx
	mov DWORD PTR[ebp-8],eax
	mov eax,DWORD PTR [ebp-8]
	mov DWORD PTR[ebp-4],eax
	mov eax,DWORD PTR [ebp-4]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:_L2

	call  _printf
L1:
	mov esp,ebp
	pop ebp
	ret
	.ident	"GCC: (GNU) 6.4.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
