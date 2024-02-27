#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    // int file;
    // file = open("myfile.txt", O_RDWR | O_CREAT, 0755);
    // if (file < 0)
    // {
    //     return 1; // err
    // }
    // char *writeThis = "I am writing to the file";
    // int writeSize;
    // writeSize = write(file, writeThis, strlen(writeThis));
    // if(writeSize < 0) {
    //     return 1; // err
    // }

    int fd, fd2;
    char buffer[100];
    fd = open("random_text.txt", O_RDWR | O_CREAT, 0777);
    fd2 = open("modified_text.txt", O_RDWR | O_CREAT, 0777);
    if((fd | fd2) < 0) {
        printf("error\n");
        return 1;
    }

    int readCount = read(fd, buffer, sizeof(buffer));
    while(readCount > 0) {
        write(fd2, buffer, readCount);
        readCount = read(fd, buffer, sizeof(buffer));
    }

    close(fd);
    close(fd2);
    return 0;
}