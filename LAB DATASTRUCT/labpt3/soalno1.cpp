#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteDuplicates(struct ListNode *head) {
    struct ListNode *current = head;
    struct ListNode *prev = NULL;
    
    while (current != NULL) {
        if (prev != NULL && current->val == prev->val) {
            prev->next = current->next; 
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

struct ListNode* arrayToList(int arr[], int size) {
    struct ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(struct ListNode *head) {
    struct ListNode *current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct ListNode *head = arrayToList(arr, size);

    printList(head);

    deleteDuplicates(head);
    printList(head);

    return 0;
}
