#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link;
};

void countNodes(struct node *head){
    int count = 0;
    if(head==NULL){
        printf("linked list belum ada");
    }
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->link;
    }
    printf("jumlah linked listnya : %d", count);
}

int main(){
    struct node *head = NULL, *newnode, *newnode2;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = 10;
    head = newnode;

    newnode = (struct node *) malloc(sizeof(struct node));
    head->link = newnode;
    newnode->data = 20;
    
    newnode2 = (struct node *) malloc(sizeof(struct node));
    newnode2->data = 30;
    head->link->link = newnode2;

    countNodes(head);

    printf("%d \n", head->data);
    printf("%d \n", newnode->data);
    printf("%p \n", head->link);
    printf("%p \n", head->link->link);
    printf("%p \n", newnode);
}