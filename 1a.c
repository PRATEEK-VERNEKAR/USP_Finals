#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    int file_size = lseek(fd, 0, SEEK_END);

    if (file_size == -1) {
        perror("lseek");
        return 1;
    }

    for (int i = 1; i <= file_size; i++) {
        lseek(fd, -i, SEEK_END);
        char c;
        if (read(fd, &c, 1) != 1) {
            perror("read");
            return 1;
        }
        putchar(c);
    }
    printf("\n");
    close(fd);
    return 0;
}