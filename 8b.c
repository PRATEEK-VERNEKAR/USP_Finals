#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t pid;
    int status;
    pid_t parent_pid = getpid();
    
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        pid_t child_pid = getpid();
        printf("Child process (PID: %d) executing...\n", child_pid);
        execl("./8bp1", "8bp1", "example.txt", (char *)NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } 
    else {
        printf("Parent process (PID: %d) executing...\n", parent_pid);
        waitpid(pid, &status, 0);
        printf("Parent process: Child process (PID: %d) has exited.\n", pid);
    }
    return 0;
}