#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    // using system call
    // USER GROUP OTHER
    // R W X
    int file;
    write(STDERR_FILENO, "Hello World!\n", sizeof("Hello World1\n"));
    file = open("hello.txt", O_RDWR | O_CREAT, 0755);
    if (file < 0)
    {
        printf("Error\n");
    }

    int x;
    x = close(file);
    if (x < 0)
    {
        printf("error");
        return 1;
    }

    int y;
    y = remove("hello.txt");
    return 0;
}