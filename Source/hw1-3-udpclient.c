#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main()
{
int udpSock;
struct sockaddr_in server_addr;
struct hostent *host;
char sendMsg[100], recvMsg[1024];
 long int serv_usage;
        int i;

host= (struct hostent *) gethostbyname((char *)"127.0.0.1");


if ((udpSock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
{
perror("socket");
exit(1);
}

server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(2000);
inet_pton(AF_INET,"127.0.0.1",&(server_addr.sin_addr));
bzero(&(server_addr.sin_zero),8);
socklen_t sendsize = sizeof(server_addr);

   while (1)
   {

    printf("Type Something... \n");
    fgets(sendMsg,1024,stdin);
	int s,r;

       s= sendto(udpSock,sendMsg , strlen(sendMsg), 0,(struct sockaddr *) &server_addr, sendsize);
	if ( s== -1)
	{
		printf (" error in sendto \n");
		exit(1);
	}
	r = (recvfrom(udpSock, recvMsg , 1024,0,NULL,NULL));

	if ( r == -1)
	{ 
		printf(" error in receiving from \n");
	}

	printf(" udp server echo: %s \n", recvMsg);
	printf("servers resource usage: \n" );
        for ( i =0; i<9; i++)
        {
                int recvbyte =  recvfrom(udpSock, recvMsg ,sizeof (recvmsg),0,(struct sockaddr *) &server_addr, &sendsize);
       if (recvbyte < 1)
        printf("error in recieving source usage \n");
        
         printf(" %s \n", recvMsg );
        }

   }

}
