#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];
    fd = open("random_text.txt", O_RDONLY, 0777);
    int readCount;
    readCount = read(fd, buffer, 100);
    while(readCount > 0) {
        printf("%s\n", buffer);
        readCount = read(fd, buffer, 100);
    }
    if (readCount < 0)
    {
        return 1;
    }
    else
    {
        printf("%i\n", readCount);
        printf("%s", buffer);
    }
    return 0;
}