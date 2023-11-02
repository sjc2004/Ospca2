#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid > 0) {
        // Parent process
        printf("Parent process with ID: %d\n", getpid());
        sleep(2); // Parent process sleeps for 2 seconds
        printf("Parent process exiting\n");
    } else if (child_pid == 0) {
        // Child process
        printf("Child process with ID: %d and parent ID: %d\n", getpid(), getppid());
        sleep(5); // Child process sleeps for 5 seconds
        printf("Orphan process with ID: %d and parent ID now: %d\n", getpid(), getppid());
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
