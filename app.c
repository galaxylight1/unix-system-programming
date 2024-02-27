/*
    1. ls [directory_name]
    2. ls
    3. [name] [type] [size] [permissions]
    4. error handling
*/

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void printCurrDir() {
    DIR* folder;
    struct dirent* entry;
    struct stat* buf;
    folder = opendir(".");
    while((entry = readdir(folder))) {
        printf("%s", entry->d_name);
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if(argc == 1) {
        printf("error: please use ls\n");
        return 0;
    }

    char* secondArg = argv[1];
    if(strcmp(secondArg, "ls") != 0) {
        printf("error: please use ls\n");
        return 1;
    }

    if(argc == 2) {
        printCurrDir();
        return 0;
    }

    char* thirdArg = argv[2];
    if(chdir(thirdArg) == 0) {
        printCurrDir();
        return 0;
    } else {
        printf("error: wrong dir name\n");
        return 1;
    }

    printf("\n");
    return 0;
}