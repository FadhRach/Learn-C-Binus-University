#include <stdio.h>
#include <stdlib.h>

struct Data {
    int value;
    struct Data *next;
}*head = NULL, *tail = NULL;

struct Data* newNode(int value){
    struct Data* node = (struct Data*)malloc(sizeof(struct Data));
    node->value = value;
    node->next = NULL;
    return node;
}

void pushHead(int value){
    struct Data* node = newNode(value);
    if(head == NULL){
        head = tail = node;
    } else {
        node->next = head;
        head = node;
    }
}

void pushTail(int value){
    struct Data* node = newNode(value);
    if(head == NULL){
        head = tail = node;
    } else if(head->value){
        tail->next = node;
        tail = node;
    }
}

void pushMid(int value){
    struct Data* node = newNode(value);
    if(head == NULL){
        head = tail = node;
    } else if(value < head->value){
        pushHead(value);
    } else if(value >= tail->value){
        pushTail(value);
    } else {
        struct Data *curr = head;
        while(curr->next != NULL && curr->next->value < value){
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
    }
}

struct Data* popHead(){
    if(head == NULL){
        return NULL;
    } else{
        struct Data* temp = head;
        if(head == tail){
            head = tail = NULL;
        } else{
            head = head->next;
        }     
        return temp;
    }
}

struct Data* popTail(){
    if(head == NULL){
        return NULL;
    } else{
        if(head == tail){
            struct Data *temp = head;
            head = tail = NULL;
            return temp;
        } else{
            struct Data *curr = head;
            while(curr->next != tail){
                curr = curr->next;
            }

            struct Data *temp = tail;
            curr->next = NULL;
            tail = curr;
            return temp;
        }
        
    }
}

struct Data*popMid(int value){
    if(head == NULL){
        return NULL;
    } else{
        if(head->value == value){
            popHead();
        } else if(tail->value == value){
            popTail();
        } else{
            struct Data *curr = head;
            while(curr->next != NULL && curr->next->value != value){
                curr = curr->next;
            }

            if(curr->next == NULL ){
                return NULL;
            }

            struct Data *temp = curr->next;
            curr->next = temp->next;
            return temp;
        }
        
    }
}

void popAll(){
    while(head != NULL){
        popHead();
    }
}

void printAll(){
    if(head == NULL){
        printf("No data!\n");
        return;
    }

    struct Data* curr = head;

    while(curr != NULL){
        printf("%d->", curr->value);
        curr = curr->next;
    }

    printf("\n");
}

int main(){

    pushMid(3);
    pushMid(8);
    pushMid(5);
    pushMid(6);
    pushHead(10);
    pushTail(2);
    printAll();
    


    struct Data* deleted = popMid(7);

    if(deleted == NULL){
        printf("No data deleted\n");
    }else{
        printf("Deleted %d\n", deleted->value);
    }
    free(deleted);

    popAll();
    printAll();

    return 0;
}