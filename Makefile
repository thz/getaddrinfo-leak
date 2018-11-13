run: gai_leak
	valgrind ./gai_leak does-not-resolve.

gai_leak: gai_leak.c
	gcc -pedantic -Wall $< -o $@

