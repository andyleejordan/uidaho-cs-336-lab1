stack:
	gcc -o stack -z execstack -fno-stack-protector stack.c
shellcode:
	gcc -z execstack -o call_shellcode call_shellcode.c
