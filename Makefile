stack:
	gcc -o stack -z execstack -fno-stack-protector -ggdb -static stack.c
permissions:
	chmod 4755 stack
shellcode:
	gcc -z execstack -o call_shellcode call_shellcode.c
exploit:
	gcc -o exploit exploit.c
nonrandom:
	sysctl -w kernel.randomize_va_space=0
