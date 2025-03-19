#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Fungsi untuk menambahkan elemen ke dalam BST
struct node *insertElement(struct node *tree, int val) {
    if (!tree) {
        tree = (struct node*)malloc(sizeof(struct node));
        tree->data = val;
        tree->left = tree->right = NULL;
    } else if (val < tree->data) {
        tree->left = insertElement(tree->left, val);
    } else {
        tree->right = insertElement(tree->right, val);
    }
    return tree;
}

// Traversal Preorder
void preorderTraversal(struct node *tree) {
    if (tree) {
        printf("%d ", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

// Traversal Inorder
void inorderTraversal(struct node *tree) {
    if (tree) {
        inorderTraversal(tree->left);
        printf("%d ", tree->data);
        inorderTraversal(tree->right);
    }
}

// Traversal Postorder
void postTraversal(struct node *tree) {
    if (tree) {
        postTraversal(tree->left);
        postTraversal(tree->right);
        printf("%d ", tree->data);
    }
}

// Mencari elemen terkecil
struct node *findSmallestElement(struct node *tree) {
    if (tree == NULL || tree->left == NULL) return tree;
    return findSmallestElement(tree->left);
}

// Mencari elemen terbesar
struct node *findLargestElement(struct node *tree) {
    if (tree == NULL || tree->right == NULL) return tree;
    return findLargestElement(tree->right);
}

// Menghapus elemen dari BST
struct node *deleteElement(struct node *tree, int val) {
    if (!tree) return NULL;
    
    if (val < tree->data) {
        tree->left = deleteElement(tree->left, val);
    } else if (val > tree->data) {
        tree->right = deleteElement(tree->right, val);
    } else {
        if (!tree->left) {
            struct node *temp = tree->right;
            free(tree);
            return temp;
        } else if (!tree->right) {
            struct node *temp = tree->left;
            free(tree);
            return temp;
        } else {
            struct node *temp = findSmallestElement(tree->right);
            tree->data = temp->data;
            tree->right = deleteElement(tree->right, temp->data);
        }
    }
    return tree;
}

// Menghitung total node dalam BST
int totalNodes(struct node *tree) {
    return tree ? totalNodes(tree->left) + totalNodes(tree->right) + 1 : 0;
}

// Menghitung total leaf node (node eksternal)
int totalExternalNodes(struct node *tree) {
    if (!tree) return 0;
    if (!tree->left && !tree->right) return 1;
    return totalExternalNodes(tree->left) + totalExternalNodes(tree->right);
}

// Menghitung total node internal
int totalInternalNodes(struct node *tree) {
    if (!tree || (!tree->left && !tree->right)) return 0;
    return totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1;
}

// Menentukan tinggi BST
int Height(struct node *tree) {
    if (!tree) return -1; // Perbaikan dari NULL ke -1 untuk tinggi BST kosong
    int leftHeight = Height(tree->left);
    int rightHeight = Height(tree->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Membalik BST (mirror image)
struct node *mirrorImage(struct node *tree) {
    if (tree) {
        struct node *temp = tree->left;
        tree->left = mirrorImage(tree->right);
        tree->right = mirrorImage(temp);
    }
    return tree;
}

// Menghapus seluruh BST
struct node *deleteTree(struct node *tree) {
    if (tree) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
    return NULL;
}

// Program utama dengan menu interaktif
int main() {
    int option, val;
    struct node *tree = NULL, *ptr;

    do {
        printf("\n### MENU BINARY TREE ###\n");
        printf("1. Insert Element\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Find the Smallest Element\n");
        printf("6. Find the Largest Element\n");
        printf("7. Delete an Element\n");
        printf("8. Count Total Nodes\n");
        printf("9. Count External Nodes\n");
        printf("10. Count Internal Nodes\n");
        printf("11. Determine Height\n");
        printf("12. Find Mirror Image\n");
        printf("13. Delete Tree\n");
        printf("14. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(tree);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(tree);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postTraversal(tree);
                printf("\n");
                break;
            case 5:
                ptr = findSmallestElement(tree);
                printf("Smallest element: %d\n", ptr ? ptr->data : -1);
                break;
            case 6:
                ptr = findLargestElement(tree);
                printf("Largest element: %d\n", ptr ? ptr->data : -1);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 8:
                printf("Total nodes: %d\n", totalNodes(tree));
                break;
            case 9:
                printf("Total external nodes: %d\n", totalExternalNodes(tree));
                break;
            case 10:
                printf("Total internal nodes: %d\n", totalInternalNodes(tree));
                break;
            case 11:
                printf("Height of tree: %d\n", Height(tree));
                break;
            case 12:
                tree = mirrorImage(tree);
                printf("Mirror image created.\n");
                break;
            case 13:
                tree = deleteTree(tree);
                printf("Tree deleted.\n");
                break;
            case 14:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while(option != 14);

    return 0;
}
