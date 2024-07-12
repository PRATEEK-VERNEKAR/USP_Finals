#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define FILENAME "example.txt"
#define CHAR_COUNT 20

int main() {
    int fd = open(FILENAME, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor
    int stdout_fd = dup(1); // Save the original stdout
    dup2(fd, 1); // Redirect stdout to the file

    char buffer[CHAR_COUNT + 1];
    ssize_t bytesRead = read(fd, buffer, CHAR_COUNT);
    if (bytesRead < 0) {
        perror("Error reading file");
        return 1;
    }

    buffer[bytesRead] = '\0'; // Null-terminate the string

    // Write the read characters back to the file
    write(fd, buffer, bytesRead);

    // Restore original stdout
    dup2(stdout_fd, 1);
    close(stdout_fd);
    close(fd);

    printf("Appended back to file: %s\n", buffer);
    
    return 0;
}
