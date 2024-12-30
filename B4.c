#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* node,int data){
	if(node == NULL){
		node = createNode(data);
		
	}
	if(data < node->data){
		node->left = insertNode(node->left,data);
	}else if(data> node->data){
		node->right = insertNode(node->right,data);
	}
	return node;
}




int search( Node* node, int key) {
    if (node == NULL) {
        return 0; 
    }

    if (node->data == key) {
        return 1; 
    } else if (key < node->data) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

int main() {
	Node* tree = NULL;
	
	tree = insertNode(tree, 3);
	tree = insertNode(tree, 2);
	tree = insertNode(tree, 5);
	tree = insertNode(tree, 4);
	tree = insertNode(tree, 6);

    int key;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &key);

    if (search(tree, key)) {
        printf("Da tim thay gia tri %d trong cay.\n", key);
    } else {
        printf("Khong tim thay gia tri %d trong cay.\n", key);
    }


    return 0;
}