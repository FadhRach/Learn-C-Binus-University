#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};

struct node *start = NULL;
int isCircular = 0;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_mid(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
void toggle_circular();

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n2. Display List\n3. Insert at Beginning\n4. Insert at End\n");
        printf("5. Insert at Middle\n6. Delete from Beginning\n7. Delete from End\n8. Toggle Circular\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: start = create_ll(start); break;
            case 2: start = display(start); break;
            case 3: start = insert_beg(start); break;
            case 4: start = insert_end(start); break;
            case 5: start = insert_mid(start); break;
            case 6: start = delete_beg(start); break;
            case 7: start = delete_end(start); break;
            case 8: toggle_circular(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

struct node *create_ll(struct node *start) {
    int n, i, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        start = insert_end(start);
    }
    return start;
}

struct node *display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    struct node *ptr = start;
    printf("List: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL && ptr != start);
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->prev = NULL;
    new_node->next = start;
    if (start != NULL) {
        start->prev = new_node;
    }
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = start;
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (start == NULL) {
        new_node->prev = NULL;
        start = new_node;
        return start;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    return start;
}

struct node *insert_mid(struct node *start) {
    int pos, i = 1;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = start;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    while (ptr != NULL && i < pos - 1) {
        ptr = ptr->next;
        i++;
    }
    if (ptr == NULL) {
        printf("Invalid position\n");
        return start;
    }
    new_node->next = ptr->next;
    if (ptr->next != NULL) {
        ptr->next->prev = new_node;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    return start;
}

struct node *delete_beg(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    struct node *temp = start;
    start = start->next;
    if (start != NULL) {
        start->prev = NULL;
    }
    free(temp);
    return start;
}

struct node *delete_end(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }
    struct node *ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    if (ptr->prev != NULL) {
        ptr->prev->next = NULL;
    } else {
        start = NULL;
    }
    free(ptr);
    return start;
}

void toggle_circular() {
    if (isCircular) {
        struct node *ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        ptr->next = NULL;
        isCircular = 0;
        printf("List is now non-circular.\n");
    } else {
        struct node *ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = start;
        isCircular = 1;
        printf("List is now circular.\n");
    }
}
