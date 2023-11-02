#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid; // Process ID

    printf("Enter the Process ID to kill: ");
    scanf("%d", &pid); // Allowing the user to input the Process ID

    if (kill(pid, SIGKILL) == 0) {
        printf("Process with PID %d has been killed using SIGKILL\n", pid);
    } else {
        perror("Error killing process");
        return 1;
    }

    return 0;
}
/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){
	pid_t ppid, pid, cpid;
	ppid = getpid();
	pid = fork();
	if(ppid == getpid())
		printf("Parent\n");
	else if(cpid == getpid())
		printf("Child\n");
	if(pid > 0){
		int i = 0;
		while(i++ < 5){
			printf("In the parent process.\n");
			sleep(1);
		}
	}
	else if(pid == 0){
		int i = 0;
		while(i++ < 10){
			printf("In the child process.\n");
			sleep(1);
			if(i==3){
				kill(ppid, SIGKILL);
				printf("Parent killed. I'm orphan!!!\n");
			}
		}
	}
	else{
		printf("Something bad happened\n");
		exit(EXIT_FAILURE);
	}
}
*/
