#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode TrieNode;

typedef struct ChildNode {
    char key;
    TrieNode* child;
    struct ChildNode* next;
} ChildNode;

struct TrieNode {
    int is_leaf;
    ChildNode* children;
};

TrieNode* make_trienode() {
    TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
    node->is_leaf = 0;
    node->children = NULL;
    return node;
}

ChildNode* make_childnode(char key, TrieNode* child) {
    ChildNode* node = (ChildNode*) malloc(sizeof(ChildNode));
    node->key = key;
    node->child = child;
    node->next = NULL;
    return node;
}

TrieNode* get_or_create_child(TrieNode* node, char key) {
    ChildNode* curr = node->children;
    ChildNode* prev = NULL;

    while (curr != NULL && curr->key < key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && curr->key == key)
        return curr->child;

    TrieNode* new_child = make_trienode();
    ChildNode* new_node = make_childnode(key, new_child);

    if (prev == NULL) {
        new_node->next = node->children;
        node->children = new_node;
    } else {
        new_node->next = prev->next;
        prev->next = new_node;
    }

    return new_child;
}

void insert_trie(TrieNode* root, const char* word) {
    TrieNode* curr = root;
    for (int i = 0; word[i]; i++) {
        curr = get_or_create_child(curr, word[i]);
    }
    curr->is_leaf = 1;
}

int search_trie(TrieNode* root, const char* word) {
    TrieNode* curr = root;
    for (int i = 0; word[i]; i++) {
        ChildNode* child = curr->children;
        while (child && child->key != word[i]) {
            child = child->next;
        }
        if (!child)
            return 0;
        curr = child->child;
    }
    return curr && curr->is_leaf;
}

void free_trie(TrieNode* node) {
    ChildNode* curr = node->children;
    while (curr) {
        free_trie(curr->child);
        ChildNode* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(node);
}

void print_trie(TrieNode* node, char* buffer, int depth) {
    if (node->is_leaf) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    ChildNode* curr = node->children;
    while (curr) {
        buffer[depth] = curr->key;
        print_trie(curr->child, buffer, depth + 1);
        curr = curr->next;
    }
}

int main() {
    TrieNode* root = make_trienode();

    insert_trie(root, "hello");
    insert_trie(root, "hi");
    insert_trie(root, "hat");
    insert_trie(root, "heat");

    char buffer[100];

    printf("Words in Trie:\n");
    print_trie(root, buffer, 0);

    printf("\nSearch results:\n");
    printf("hello: %s\n", search_trie(root, "hello") ? "Found" : "Not Found");
    printf("hat: %s\n", search_trie(root, "hat") ? "Found" : "Not Found");
    printf("heat: %s\n", search_trie(root, "heat") ? "Found" : "Not Found");
    printf("he: %s\n", search_trie(root, "he") ? "Found" : "Not Found");

    free_trie(root);
    return 0;
}
