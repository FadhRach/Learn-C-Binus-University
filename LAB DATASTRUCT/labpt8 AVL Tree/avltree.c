#include <stdio.h>

// UAP NOTED =============================================
//  1 soal uap close book close internet dari awal ampe akhir

struct Node {
    int key, height;
    struct Node *left, *right;
}

int max(int a, int b){
    return (a>b) ? a : b;
}

int height(struct Node *N){
    return(N == NULL) ? 0 : N->height;
}

struct Node *newNode(int key){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y){
	struct Node *x = y->left;
	struct Node *T2 = y->right;
	
	x->right = y;
	y->left = T2;
	
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	
	return x;
}

struct Node *leftRotate(struct Node *x){
	struct Node *y = x->left;
	struct Node *T2 = y->left;
	
	x->left = x;
	y->right = T2;
	
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	
	return x;
}

int getBalance(struct Node *N){
	return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

struct Node *insertionNode(struct Node *node, int key){
	if(node == NULL) return newNode(key);
	if(key < node->key){
		node->left = insertionNode(node->left, key);
	} else if (key > node->key){
		node->right = insertionNode(node->right, key);
	} else{
		return node;
	}
	
	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);
	
	//left left case
	if(balance > 1 && key < node->left->key){
		return rightRotate(node)
	}
	//right right case
	if(balance < -1 && key > node->right->key){
		return leftRotate(node)
	}
	// left right case
	if(balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	//Right Left Case
	if(balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	
}

int main() {

    printf("hai");

    return 0;
}