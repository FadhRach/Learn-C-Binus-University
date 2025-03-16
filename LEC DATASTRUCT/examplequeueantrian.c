#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE 10

typedef struct {
    char passengers[MAX_QUEUE][50];
    int front, rear;
} BoardingQueue;

BoardingQueue* createQueue() {
    BoardingQueue* queue = (BoardingQueue*)malloc(sizeof(BoardingQueue));
    queue->front = queue->rear = 0;
    return queue;
}

void enqueue(BoardingQueue* queue, char name[]) {
    if (queue->rear < MAX_QUEUE) {
        strcpy(queue->passengers[queue->rear++], name);
    } else {
        printf("Antrian penuh!\n");
    }
}

void dequeue(BoardingQueue* queue) {
    if (queue->front < queue->rear) {
        printf("Boarding: %s\n", queue->passengers[queue->front++]);
    } else {
        printf("Tidak ada penumpang dalam antrian!\n");
    }
}

int isEmpty(BoardingQueue* queue) {
    return queue->front == queue->rear;
}

int main() {
    BoardingQueue* queue = createQueue();

    enqueue(queue, "Andi");
    enqueue(queue, "Budi");
    enqueue(queue, "Citra");

    dequeue(queue);
    dequeue(queue);

    free(queue);
    return 0;
}
