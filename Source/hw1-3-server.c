
/* TCP/UDP server */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/resource.h>

int main()

{

	int sock_desc, client_sock, c, read_req;
	struct sockaddr_in server, client;
	char client_request [20];	// setting client request char lenght
	
	struct rusage r_usage;   //struct for getrusage()
	char send_data[100];
	// create socket
	sock_desc = socket(AF_INET, SOCK_STREAM, 0);
	if ( sock_desc == -1 )
	{
		printf(" could not create socket \n"); // display message for socket creation failure
		exit(1);
	}
	 printf (" socket created \n");

	// sockaddr_in struck
	
	server.sin_family = AF_INET;
 	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(9005);

	// Bind creation
	if ( bind (sock_desc, (struct sockaddr * )&server, sizeof(server ) ) == -1)
	 {
                printf(" could not create bind \n"); // display message for bind creation failure
		exit(1);
        }
         printf (" bind  created \n");

	// listen
//	if ( listen (sock_desc, 0) == -1)
//	{
//		printf( " error listening \n" );	
//		perror("listen");
//		exit(1);
//	}

	  listen(sock_desc, 5); 
            
            
	
	// accept and echo the request from the client
	printf (" Waiting for client request... ");

	c= sizeof(struct sockaddr_in);
	
	if ( client_sock= accept(sock_desc, (struct sockaddr* )&client , (socklen_t*)&c) == -1)
	 {
                printf(" accept failed... "); // display message for accept failure
		exit(1);
        }
	printf (" accepted client request...");
	
	while((read_req = recv(client_sock, client_request,10,0))>0)
	{
		getrusage(RUSAGE_SELF, &r_usage);
		//send_data = r_usage;
		send(client_sock, &r_usage , 0, 0);
	}
 	 if( read_req == 0)
	 {
      		  puts("Client disconnected");
      		  fflush(stdout);
   	 }
    	else if(read_req == -1)
   	 {
        	perror("recv failed");
   	 }
     
    return 0;
}



