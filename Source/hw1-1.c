/*
 * hw1-1.c
 *
 *  Created on: Sep 21, 2014
 *      Author: nandan
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void forkChild (int nProcess) {
    int i;
    int pid;
    for (i = 1; i <= nProcess; i++) {
        pid = fork();
    
        if (pid == 0) {
            printf("I am a child: %d PID: %d\n",i, getpid());
            sleep (5);
            return;
        }
}
}
int main () {
    
	
        forkChild (5);
    
    return 0;
}
