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