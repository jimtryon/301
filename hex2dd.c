// Jim Tryon
// 12-5-2014
// This program takes a hex value and converts it to
// a dotted decimal string.

#include "csapp.h"

int main(int argc, char **argv)
{
	struct in_addr inaddr;	/* addr in network byte order */
	unsigned int addr; 		/* addr in host byte order */

	// Checks for the correct number of arguments to the program
	if (argc != 2) {
		fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
		exit(0);
	}
	// Accepts an ip address as user input
	sscanf(argv[1], "%x", &addr);
	// Converts the ip address to a readable network address
	inaddr.s_addr = htonl(addr);
	// Prints out the result
	printf("%s\n", inet_ntoa(inaddr));

	exit(0);
}