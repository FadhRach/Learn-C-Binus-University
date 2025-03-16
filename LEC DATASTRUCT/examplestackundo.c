#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNDO 100

typedef struct {
    char actions[MAX_UNDO][100];
    int top;
} UndoStack;

UndoStack* createStack() {
    UndoStack* stack = (UndoStack*)malloc(sizeof(UndoStack));
    stack->top = -1;
    return stack;
}

void push(UndoStack* stack, char action[]) {
    if (stack->top < MAX_UNDO - 1) {
        strcpy(stack->actions[++stack->top], action);
    } else {
        printf("Undo Stack penuh!\n");
    }
}

void pop(UndoStack* stack) {
    if (stack->top >= 0) {
        printf("Undo: %s\n", stack->actions[stack->top--]);
    } else {
        printf("Tidak ada aksi yang bisa di-undo!\n");
    }
}

int isEmpty(UndoStack* stack) {
    return stack->top == -1;
}

int main() {
    UndoStack* undoStack = createStack();

    push(undoStack, "Mengetik: 'Hello'");
    push(undoStack, "Mengetik: ' World!'");
    push(undoStack, "Menghapus: ' World!'");

    pop(undoStack); // Undo terakhir -> Menghapus ' World!'
    pop(undoStack); // Undo sebelumnya -> Mengetik ' World!'

    free(undoStack);
    return 0;
}
