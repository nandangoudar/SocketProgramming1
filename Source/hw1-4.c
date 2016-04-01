#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <sys/resource.h> 
#include <netinet/in.h>
#include <unistd.h> 
#include <arpa/inet.h>
#define ASCII_for_CR 0x0D   // defining asci value for CR
#define ASCII_for_LF 0x0A	//defining ascii value for LF

int main(int argc,char **argv)
{
    int sockfd,n,i;
    char sendline[100];
    char recvline[1024];
char *str = recvline;
    struct sockaddr_in servaddr;
     char cr = ASCII_for_CR , lf = ASCII_for_LF;	// taking the asci values in char cr and lf for using

     sockfd=socket(AF_INET,SOCK_STREAM,0);		//create tcp socket
      if (sockfd == -1)
	{  printf("socket creation failed \n");
	}

    bzero(&servaddr,sizeof servaddr); 
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(79);
 
    inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
	
 int conn;
	conn = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));	// connecting to server 127.0.0.1 (localhost machine
	if (conn == -1)
	{	printf ("connect failed \n");
		exit(1);
	}
	printf("connect successful \n");

//  int serv_usage;
//	uint32_t x ; 

	


    
    
        bzero( sendline, 100);
        bzero( recvline, 1024);
//	bzero( serv_usage, 10);
        printf("query finger deamon \n");

	fgets(sendline,100,stdin); //stdin = 0 , for standard input 
	
	write(sockfd, sendline,100);  // send the input argument from console cli
	write(sockfd, &cr ,1);		// end the fingerd query with "CRLF"
	write(sockfd, &lf,1);	
	n=read(sockfd,recvline,1024);  // reading the response
   
	printf ("%d\n", n);		
      for (i=0; i<n ; i++)		
      {
         if (recvline[i]==ASCII_for_CR) continue; /* Presume part of CR-LF pair */
        
	 printf(" %c", recvline[i]);			// printing the recieved charater from fingerd query
      }
		  
	
    
 
close(sockfd);

}
