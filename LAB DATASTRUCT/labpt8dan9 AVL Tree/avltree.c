#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key, height;
    struct Node *left, *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *N) {
    return (N == NULL) ? 0 : N->height;
}

struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *N) {
    return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

struct Node *insertionNode(struct Node *node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insertionNode(node->left, key);
    else if (key > node->key)
        node->right = insertionNode(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node *minValueNode(struct Node *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        struct Node *temp;
        if (root->left == NULL || root->right == NULL) {
            temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
                free(temp);
            } else {
                *root = *temp;
                free(temp);
            }
        } else {
            temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printPreOrder(struct Node *root) {
    if (root) {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    int keys[] = {2, 1, 7, 4, 5, 3, 8};
    for (int i = 0; i < 7; i++) {
        root = insertionNode(root, keys[i]);
    }

    printf("Sebelum delete:\n");
    printPreOrder(root);
    printf("\n");

    root = deleteNode(root, 3);

    printf("Setelah delete 3:\n");
    printPreOrder(root);
    printf("\n");

    return 0;
}
