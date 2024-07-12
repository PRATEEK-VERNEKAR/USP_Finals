#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) exiting.\n", getpid());
        exit(0);
    } else {
        // Parent process
        printf("Parent process (PID: %d) created child process (PID: %d).\n", getpid(), pid);
        printf("Parent process sleeping for 10 seconds. Check the child process status with `ps` command.\n");
        sleep(10); // Sleep to keep the child in a zombie state
        printf("Parent process waking up and calling wait().\n");
        wait(NULL); // Collect the child's exit status
        printf("Parent process collected child's exit status. Exiting.\n");
    }

    return 0;
}
