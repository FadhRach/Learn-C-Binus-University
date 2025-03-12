#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    while (list1 && list2) {
        struct ListNode* temp;
        if (list1->val < list2->val) {
            temp = list1;
            list1 = list1->next;
        } else {
            temp = list2;
            list2 = list2->next;
        }
        
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    if (list1) tail->next = list1;
    if (list2) tail->next = list2;
    
    return head;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* createList(int n) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int val;
        printf("Masukkan elemen ke-%d: ", i + 1);
        scanf("%d", &val);
        
        struct ListNode* newNode = createNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    int n1, n2;
    
    printf("Masukkan jumlah elemen dalam list1: ");
    scanf("%d", &n1);
    struct ListNode* list1 = createList(n1);
    
    printf("Masukkan jumlah elemen dalam list2: ");
    scanf("%d", &n2);
    struct ListNode* list2 = createList(n2);
    
    struct ListNode* mergedList = merge(list1, list2);
    
    printf("Merged Linked List: ");
    printList(mergedList);
    
    return 0;
}