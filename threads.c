#include <pthread.h>
#include <stdio.h>

void *threadSafe(void *vargp) {
    printf("Hello from the thread!\n");
}

int main() {
    pthread_t id;
    pthread_create(&id, NULL, threadSafe, NULL);
    pthread_join(id, NULL);
    printf("After thread finished\n");
    return 0;
}