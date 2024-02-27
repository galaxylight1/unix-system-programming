#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
    int pid, y, z;
    char *arg[1] = {0};
    pid = fork();
    if(pid == 0) {
        execv("app", arg);
    }
    
    y = wait(&z);
    exit(0);
}