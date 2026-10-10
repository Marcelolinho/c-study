#include <pthread.h>
#include <stdio.h>

pthread_t threads[4];
int ids[4];

void* printThread(void* args) {
    int* pointer = (int*) args;
    int id = *pointer;
    printf("Oi da Thread %d\n", id);
}

int main(void) {
    
    for (int i = 0; i < 4; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, printThread, &ids[i]);
    }
    
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;

}