/* code called by execve in child process of main program name: hw1-2.c */

#include <stdlib.h>
#include <stdio.h>

main(int argc,char *argv[],char *envp[]) // recieving arguments from execv function called from child process
 {
int i;
int sum=0;


// loop to do summation of number from 1 to 5;

for (i=1 ; i<=5 ; i++) {
printf ("The value of i is %d\n", i);
sum += i;
}
printf ("The sum is %d\n", sum);
exit (0);

}
