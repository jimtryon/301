#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

void error(char *msg)
{
	// print a string to a file
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int open_socket(char *host, char *port)
{
	struct addrinfo *res;
	struct addrinfo hints;

	// zero out the structure
	memset(&hints, 0, sizeof(hints));
	// doesn't specify internet protocol (IPv4 or IPv6)
	hints.ai_family = PF_UNSPEC;
	// create a stream socket
	hints.ai_socktype = SOCK_STREAM;

	if (getaddrinfo(host, port, &hints, &res) == -1)
	{
		error("Can't resolve the address");
	}

	int d_sock = socket(res->ai_family, res->ai_socktype,
		res->ai_protocol);

	if (d_sock == -1)
	{
		error("Can't open socket");
	}

	int c = connect(d_sock, res->ai_addr, res->ai_addrlen);

	// Free up the memory
	freeaddrinfo(res);

	if (c == -1)
	{
		error("Can't connect to socket");
	}
	return d_sock;
}

int say(int socket, char *s)
{
	int result = send(socket, s, strlen(s), 0);

	if (result == -1)
	{
		fprintf(stderr, "%s: %s\n", "Error talking to the server",
			strerror(errno));
	}
	return result;
}

int main(int argc, char *argv[])
{

	int d_sock;

	d_sock = open_socket("en.wikipedia.org", "80");
	char buf[255];

	sprintf(buf, "GET /wiki/%s HTTP/1.1\r\n", argv[1]);		// create a string for the path
	say(d_sock, buf);								// of the page

	say(d_sock, "Host: en.wikipedia.org\r\n\r\n");	// sends the host data and blank line
	char rec[256];
	int bytesRcvd = recv(d_sock, rec, 255, 0);
	while (bytesRcvd) 
	{
		if (bytesRcvd == -1)
		{
			error("Can't read from server");
		}
		rec[bytesRcvd] = '\0';	// add a \0 to make it a proper string
		printf("%s", rec);
		bytesRcvd = recv(d_sock, rec, 255, 0);
	}
	close(d_sock);
	return 0;
}
