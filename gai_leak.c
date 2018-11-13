/*
 * Example code for getaddrinfo memory leak with eglibc-2.19.
 *
 * Tobias Hintze <th-git@thzn.de>, 2018
 *
 *
 * Valgrind will detect memory leaks within getaddrinfo()
 * when run on ubuntu-14.04 userland (eglibc-2.19) for some
 * names.
 *
 * A non-existing hostname with a trailing dot (forcing fqdn)
 * is one example which triggers the leak.
 *
 * PF_UNSPEC is essential. Limited name resolve (v4/v6 only)
 * does not trigger the problem.
 *
 */

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>


/*
 * name to resolve expected as argv[1]
 */
int main(int argc, char **argv) {
	int error;
	const char *nodename = argv[1];
	struct addrinfo *aihead = NULL;

	struct addrinfo hints;

	if (argc != 2) return 1;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	error = getaddrinfo(nodename, NULL, &hints, &aihead);
	if (error) {
		printf("getaddrinfo returned %d (%s).\n", error, gai_strerror(error));
	} else if (aihead) {
		freeaddrinfo(aihead);
	}
	return 0;
}
