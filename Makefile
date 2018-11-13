run: gai_leak
	valgrind \
		--error-exitcode=1 \
		--errors-for-leak-kinds=definite \
		--leak-check=full \
		./gai_leak does-not-resolve.

gai_leak: gai_leak.c
	gcc -pedantic -Wall $< -o $@

