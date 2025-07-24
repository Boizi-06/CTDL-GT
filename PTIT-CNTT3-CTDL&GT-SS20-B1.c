#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* taoNode() {
    int x;
    printf("Nhap so nguyen cho Node: ");
    scanf("%d", &x);


    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai.\n");
        exit(1);
    }

    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


int main() {
    Node* node = taoNode();
    printf("\nNode vua tao:\n");
    printf("data: %d\n", node->data);
    printf("left -> %p\n", (void*)node->left);
    printf("right -> %p\n", (void*)node->right);
    free(node);
    return 0;
}
