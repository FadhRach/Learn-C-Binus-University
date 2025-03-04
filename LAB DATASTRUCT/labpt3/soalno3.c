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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
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

int main() {
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);
    list1->next->next->next = createNode(10);
    printList(list1);
    
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(8);
    list2->next->next = createNode(6);
    printList(list2);
    
    struct ListNode* mergedList = mergeTwoLists(list1, list2);
    

    // Mencetak hasil
    printf("Merged Linked List: ");
    printList(mergedList);
    
    return 0;
}