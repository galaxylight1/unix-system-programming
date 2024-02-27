#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // using system call
    int file;
    write(STDERR_FILENO, "Hello World!\n", sizeof("Hello World1\n")); 
    file = open("hello.txt", O_RDWR | O_CREAT, 0755);
    if(file < 0) {
        printf("Error\n");
    }
    return 0;
}