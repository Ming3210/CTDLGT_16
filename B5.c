#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMax(Node* node) {
    if (node == NULL) {
        return -1; 
    }

    int result = node->data;
    int leftResult = findMax(node->left);
    int rightResult = findMax(node->right);

    if (leftResult > result) {
        result = leftResult;
    }
    if (rightResult > result) {
        result = rightResult;
    }
    return result;
}

int main() {
    Node* tree = createNode(1);
    tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);
    tree->right->left = createNode(6);
    tree->right->right = createNode(7);

    int max = findMax(tree);
    printf("Gia tri lon nhat trong cay la: %d\n", max); 

}