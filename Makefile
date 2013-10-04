stack:
	gcc -o stack -z execstack -fno-stack-protector -ggdb -static stack.c
shellcode:
	gcc -z execstack -o call_shellcode call_shellcode.c
exploit:
	gcc -o exploit exploit.c
