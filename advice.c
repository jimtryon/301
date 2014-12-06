// Jim Tryon
// 11-21-14
// This program creates a server that gives advice.

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,  char *argv[])
{
	char *advice[] = {
		// Create a character array for messages
		"Live life to the fullest.r\n",
		"Remember: Think, before you speak.\r\n",
		"One word: inappropriate\r\n",
		"Be yourself.\r\n",
		"You are your worst critic.\r\n"
	};

	int listener_d = socket(PF_INET, SOCK_STREAM, 0); 	// Create a socket

	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(30000);			// Bind socket to 30000
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(listener_d, (struct sockaddr *) &name, sizeof(name));
	listen(listener_d, 10);		// Set to the listen queue depth to 10
	puts("Waiting for connection");

	while (1) {		// You need to loop the accept/begin talking section.
		struct sockaddr_storage client_addr;
		unsigned int address_size = sizeof(client_addr);
		// Accept a connection from a client
		int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
		char *msg = advice[rand() % 5];
		send(connect_d, msg, strlen(msg), 0);		// Begin talking to the client
		close(connect_d);
		}
		return 0;		
}