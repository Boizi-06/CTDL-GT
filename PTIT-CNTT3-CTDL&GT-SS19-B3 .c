//
// Created by admin on 7/21/2025.
//
//
// Created by admin on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* creatNode() {
    int value;
    printf("Nhap gia tri cho node: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


void preorder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;

    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->data);
}

void  inorder (struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);

}
void freeTree(struct Node* root) {
    if (root == NULL) return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("Tao node goc (root):\n");
    struct Node* root = creatNode();

    printf("Tao node ben trai cua %d:\n", root->data);
    root->left =creatNode();

    printf("Tao node ben phai cua %d:\n", root->data);
    root->right = creatNode();
    printf("Tao node ben trai cua %d:\n", root->left->data);
    root->left->left =creatNode();


    preorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}
