#include <pthread.h>
#include <stdio.h>

// int ids[4];

void* monteCarlo(void* args) {
    int* pointer = (int*) args;
    int id = *pointer;
    printf("Oi da Thread %d\n", id);
}

int main(int argc, char *argv[]) {
    int areaSquare = 2;

    if (argc == 1) {
        return 0;
    }

    int numThreads = *argv[1];
    pthread_t threads[numThreads];
    // int ids[numThreads];
    
    for (int i = 0; i < numThreads; i++) {
        // ids[i] = i;
        pthread_create(&threads[i], NULL, monteCarlo, );
    }
    
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;

}