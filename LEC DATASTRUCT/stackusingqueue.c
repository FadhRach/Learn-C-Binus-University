#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int* q1;
    int* q2;
    int front1, rear1, front2, rear2;
    int size;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = (int*)malloc(100 * sizeof(int));
    stack->q2 = (int*)malloc(100 * sizeof(int));
    stack->front1 = stack->rear1 = 0;
    stack->front2 = stack->rear2 = 0;
    stack->size = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->q2[obj->rear2++] = x;
    
    while (obj->front1 < obj->rear1) {
        obj->q2[obj->rear2++] = obj->q1[obj->front1++];
    }

    int* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    obj->front1 = 0;
    obj->rear1 = obj->rear2;
    obj->front2 = obj->rear2 = 0;

    obj->size++;
}

bool myStackEmpty(MyStack* obj) {
    return obj->front1 == obj->rear1;
}

int myStackPop(MyStack* obj) {
    if (myStackEmpty(obj)) return -1;
    return obj->q1[obj->front1++];
}

int myStackTop(MyStack* obj) {
    if (myStackEmpty(obj)) return -1;
    return obj->q1[obj->front1];
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

