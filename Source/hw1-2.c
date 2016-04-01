#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>


main() {


fork();

char *tmp[]={"child"}; 
if (fork()!=0) 
{
exit(1);
}
else // checking the condition for child process
{
	execve("hw1-2-child_process", tmp, NULL); // calling the execve function from child process 
	printf("ERROR \n");				// will print an error if execve command execution fails

}
}
