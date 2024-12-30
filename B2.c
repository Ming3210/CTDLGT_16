#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
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



void preorderTraversal(Node* node){
	if(node != NULL){
		printf("%d\t",node->data);
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
}

void inorderTraversal(Node* node){
	if(node != NULL){
		inorderTraversal(node->left);   
        printf("%d\t", node->data);    
        inorderTraversal(node->right);
	}
}

void postorderTraversal(Node* node){
	if(node != NULL){
		postorderTraversal(node->left);   
        postorderTraversal(node->right);
        printf("%d\t", node->data);    
	}
}

void levelorderTraversal(Node* node){
	
}

int main(){
	Node* tree = NULL;
	
	tree = insertNode(tree, 3);
	tree = insertNode(tree, 2);
	tree = insertNode(tree, 5);
	tree = insertNode(tree, 4);
	tree = insertNode(tree, 6);
	
	postorderTraversal(tree);
	return 0;
}
