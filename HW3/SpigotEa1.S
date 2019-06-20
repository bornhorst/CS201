#ryan bornhorst
#cs201 
#hw3
.global SpigotE


.text

SpigotE:
	
	movq $2,(%rdi)#output[0]
	movq %rdx,%rbx#mov n to rbx
	addq $1,%rbx#i = n + 1
	
	Buffer:
		movq $1,%r13#initialize buffer to all 1s
		addq (%rsi),%r13
		addq $1,%rsi
		subq $1,%rbx
		cmpq $0,%rbx
		jge Buffer

	movq %rdx,%rbx#mov n to rbx
	addq $1,%rbx#i = n +1
	movq %rbx,%r9
	addq $2,%r9#i+2
	addq $1,%rdi#output[1]
	movq $1,%r11#j= 1
	movq %rdx,%r12 #also equal to n
	subq $1,%rsi

	Output:
		movq $0,%r10#q
		movq %rbx,%r9
		addq $2,%r9#r9 = i+2

		Temp:
		
			movq $10,%r8#temp
			imulq %r13,%r8#workbuffer[6] * 10
			addq %r10,%r8#+q
						
	
		
			movq $0,%rdx	
			movq %r8,%rax#put temp into rax
			movq %r9,%rcx#put i+2 into rcx 
			divq %rcx
			movq %rax,%r10#q = quotient
			movq %rdx,%r14#remainder
			subq $1,%r9
			subq $1,%rsi
			cmpq $2,%r9
			jge Temp
		
		
	
						
		movq %r10,(%rdi)#store value in output
		addq $1,%rdi
		addq $1,%r11
		cmpq %r12,%r11#continue if j < n
		jl Output
					
					
			

	ret
