#include <stdio.h>
#include <stdlib.h>

// Struktur untuk node linked list
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Fungsi untuk membalikkan linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Fungsi untuk mengecek apakah linked list palindrome
int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1; // List kosong atau satu elemen adalah palindrome
    }

    // Langkah 1: Temukan tengah list dengan slow dan fast pointer
    struct Node *slow = head, *fast = head, *prev_slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    // Pisahkan list menjadi dua bagian
    prev_slow->next = NULL;
    struct Node* secondHalf = slow;

    // Langkah 2: Balikkan bagian kedua
    secondHalf = reverseList(secondHalf);

    // Langkah 3: Bandingkan bagian pertama dan kedua
    struct Node* firstHalf = head;
    while (firstHalf != NULL && secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return 0; // Bukan palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1; // Palindrome
}

// Fungsi untuk mencetak linked list (opsional untuk debugging)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf("->");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Membuat linked list: 1->2->1->1->2->1
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(2);

    // Cetak linked list (opsional)
    printf("Linked List: ");
    printList(head);

    // Cek apakah palindrome
    if (isPalindrome(head)) {
        printf("Output: palindrome\n");
    } else {
        printf("Output: bukan palindrome\n");
    }

    // Bersihkan memori (opsional, untuk praktek yang baik)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}