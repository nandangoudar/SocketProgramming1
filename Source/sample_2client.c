#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <sys/resource.h> 
#include <unistd.h> 
#include <arpa/inet.h>
int main(int argc,char **argv)
{
    int sockfd,n;
    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;
 
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if (sockfd== -1)
	printf ("error in scoket creation \n");
    printf(" socket created \n");
	bzero(&servaddr,sizeof servaddr);
 
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(22000);
 
    inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
 
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
 long int serv_usage;

	uint32_t x ; 
	
    while(1)
    {
        bzero( sendline, 100);
        bzero( recvline, 100);
//	bzero( serv_usage, 10);
        fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
 
        write(sockfd,sendline,strlen(sendline));
        read(sockfd,recvline,100);
	printf("recieved echo respose from server: %s \n", recvline); 
sleep (2);
	int i;	
	for ( i =0; i<9; i++)
	{
		int recvbyte =	recv(sockfd, &x,sizeof (uint32_t),0);
       if (recvbyte < 1)
	printf("error in recieving source usage \n");
	serv_usage = ntohl (x);
	 printf(" %ld \n", serv_usage );
	}
    }
 
}
