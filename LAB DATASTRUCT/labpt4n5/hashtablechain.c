#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAPACITY 10

struct HashNode {
    int key;
    char* value;
    struct HashNode* next;
};

struct HashTable {
    struct HashNode** buckets;
    int numOfBuckets; // Kapasitas hash table
    int size; // Jumlah elemen saat ini
};

struct HashTable* createHashTable(int capacity) {
    struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable));
    table->numOfBuckets = capacity;
    table->buckets = (struct HashNode**)malloc(capacity * sizeof(struct HashNode*));
    table->size = 0;
    for (int i = 0; i < capacity; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

int getBucketIndex(struct HashTable* table, int key) {
    return key % table->numOfBuckets;
}

void put(struct HashTable* table, int key, const char* value) {
    int bucketIndex = getBucketIndex(table, key);
    struct HashNode* head = table->buckets[bucketIndex];

    // Pemeriksaan apabila key sudah ada di bucket
    while (head != NULL) {
        if (head->key == key) {
            free(head->value);
            head->value = strdup(value);
            return;
        }
        head = head->next;
    }

    // Jika key tidak ditemukan, tambahkan elemen baru di linked list
    table->size++;
    head = table->buckets[bucketIndex];
    struct HashNode* node = (struct HashNode*)malloc(sizeof(struct HashNode));
    node->key = key;
    node->value = strdup(value);
    node->next = head;
    table->buckets[bucketIndex] = node;
}

char* get(struct HashTable* table, int key) {
    int bucketIndex = getBucketIndex(table, key);
    struct HashNode* head = table->buckets[bucketIndex];
    struct HashNode* previous = NULL; // Diperlukan deklarasi ini

    while (head != NULL) {
        if (head->key == key) {
            return head->value; // Kalau ketemu
        }
        previous = head;
        head = head->next;
    }
    return NULL;
}

char* removeKey(struct HashTable* table, int key) {
    int bucketIndex = getBucketIndex(table, key);
    struct HashNode* head = table->buckets[bucketIndex];
    struct HashNode* previous = NULL;

    while (head != NULL) {
        if (head->key == key) {
            break;
        }
        previous = head;
        head = head->next;
    }
    if (head == NULL) return NULL;
    
    table->size--;
    if (previous != NULL) {
        previous->next = head->next;
    } else {
        table->buckets[bucketIndex] = head->next;
    }

    char* value = head->value;
    free(head);
    return value;
}

void displayHashTable(struct HashTable* table) {
    for (int i = 0; i < table->numOfBuckets; i++) {
        printf("[%d]: ", i);
        struct HashNode* node = table->buckets[i];
        while (node != NULL) {
            printf("(%d, %s) -> ", node->key, node->value);
            node = node->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable* table = createHashTable(DEFAULT_CAPACITY);

    put(table, 105, "Andi");
    put(table, 21, "Budi");
    put(table, 15, "Candra");
    // put(table, 21, "Mita"); // Coba update nilai

    printf("Hash table setelah penyimpanan:\n");
    displayHashTable(table);

    return 0;
}
