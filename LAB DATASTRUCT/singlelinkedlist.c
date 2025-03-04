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

void removeDuplicates(){
    struct Data *curr = head;
    while(curr != NULL && curr->next != NULL){
        struct Data *runner = curr;
        while(runner->next != NULL){
            if(curr->value == runner->next->value){
                struct Data *temp = runner->next;
                runner->next = runner->next->next;
                if(temp == tail){
                    tail = runner;
                }
                free(temp);
            } else{
                runner = runner->next;
            }
        }
        curr = curr->next;
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

int isPalindromeList() {
    if (head == NULL || head->next == NULL) return 1; // Kosong atau 1 elemen adalah palindrome

    // Langkah 1: Temukan tengah dengan slow dan fast pointer
    struct Data *slow = head;
    struct Data *fast = head;
    struct Data *prev_slow = NULL; // Untuk menyimpan node sebelum slow
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next; // Bergerak 2 langkah
        prev_slow = slow;        // Simpan sebelumnya
        slow = slow->next;       // Bergerak 1 langkah
    }
    
    // Jika panjang ganjil, tengah adalah slow, lewati node tengah
    struct Data *mid = slow;
    prev_slow->next = NULL; // Pisahkan bagian kiri
    
    // Langkah 2: Balikkan bagian kanan
    struct Data *prev = NULL;
    struct Data *curr = mid;
    struct Data *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    struct Data *right = prev; // Head dari bagian kanan yang dibalik
    
    // Langkah 3: Bandingkan kiri dan kanan
    struct Data *left = head;
    while (left != NULL && right != NULL) {
        if (left->value != right->value) {
            return 0; // Bukan palindrome
        }
        left = left->next;
        right = right->next;
    }
    
    return 1; // Palindrome
}

int main(){

    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(3);
    pushTail(2);
    pushTail(1);
    printAll();
    
    if (isPalindromeList()) {
        printf("Linked list adalah palindrome\n");
    } else {
        printf("Linked list bukan palindrome\n");
    }

    printAll();

    struct Data* deleted = popMid(7);

    if(deleted == NULL){
        printf("No data deleted\n");
    }else{
        printf("Deleted %d\n", deleted->value);
    }
    free(deleted);

    // removeDuplicates();
    printAll();
    

    printAll();

    return 0;
}