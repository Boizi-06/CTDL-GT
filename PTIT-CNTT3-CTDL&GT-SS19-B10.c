//
// Created by admin on 7/21/2025.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tao node moi
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Tim node theo gia tri
Node* findNode(Node* root, int value) {
    if (root == NULL) return NULL;

    if (root->data == value) return root;

    Node* left = findNode(root->left, value);
    if (left != NULL) return left;

    return findNode(root->right, value);
}

// Tao cay
void createTree(Node** root) {
    int choice, value;
    int rs = 0;

    if (*root == NULL) {
        printf("Cay cua ban chua co goc\n");
        printf("Moi ban khoi tao gia tri o goc: ");
        scanf("%d", &value);
        getchar();
        *root = createNode(value);
    } else {
        do {
            printf("Nhap node ma ban muon them nhanh: ");
            scanf("%d", &value);
            getchar();
            Node* find = findNode(*root, value);
            if (!find) {
                printf("Node ban muon them khong ton tai\n");
            } else {
                printf("Nhap gia tri cua node moi muon them: ");
                int newValue;
                scanf("%d", &newValue);
                getchar();

                do {
                    printf("Nhap nhanh ma ban muon them (1 = trai | -1 = phai): ");
                    scanf("%d", &choice);
                    getchar();

                    if (choice == 1) {
                        if (newValue >= find->data) {
                            printf("Vi la cay tim kiem nen gia tri nhanh trai phai nho hon node cha!\n");
                        } else if (find->left != NULL) {
                            printf("Nhanh trai da co node! Moi nhap lai\n");
                        } else {
                            find->left = createNode(newValue);
                            rs = 1;
                            break;
                        }
                    } else if (choice == -1) {
                        if (newValue <= find->data) {
                            printf("Vi la cay tim kiem nen gia tri nhanh phai phai lon hon node cha!\n");
                        } else if (find->right != NULL) {
                            printf("Nhanh phai da co node! Moi nhap lai\n");
                        } else {
                            find->right = createNode(newValue);
                            rs = 1;
                            break;
                        }
                    } else {
                        printf("Chi duoc nhap 1 hoac -1!\n");
                    }
                } while (1);
            }

            if (rs == 1) break;

        } while (1);
    }
}

// Duyet cay theo thu tu trung to
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Ham kiem tra cay co phai la BST khong
int isBST(Node* root, int min, int max) {
    if (root == NULL) return 1;

    // Neu vi pham nguyen tac BST
    if (root->data <= min || root->data >= max)
        return 0;

    // De quy kiem tra nhanh trai va phai
    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

// Ham goi chinh
int checkBinarySearchTree(Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Tao cay\n");
        printf("2. Duyet cay (Inorder)\n");
        printf("3. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            createTree(&root);  // Truyen dia chi con tro
        } else if (choice == 2) {
            if (root == NULL) {
                printf("Cay rong!\n");
            } else {
                printf("Cay theo thu tu trung to (Inorder): ");
                inorder(root);
                printf("\n");
            }
        } else if (choice == 3) {
            printf("Tam biet!\n");
        } else {
            printf("Lua chon khong hop le. Moi nhap lai.\n");
        }

    } while (choice != 3);
    int c = checkBinarySearchTree(root);
    return 0;
}
