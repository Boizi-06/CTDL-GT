//
// Created by admin on 7/22/2025.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;


Node *creatNode(int value) {
    Node *r = (Node *) malloc(sizeof(Node));
    if (r == NULL) {
        return NULL;
    }
    r->data = value;
    r->left = r->right = NULL;
    return r;
}

Node *findNode(Node *root, int value) {
    if (root == NULL) return NULL;

    if (root->data == value) return root;

    Node *left = findNode(root->left, value);
    if (left != NULL) return left;

    return findNode(root->right, value);
}


// ham khoi tao cay nhi phan
void creaTree(Node **root) {
    int value;
    if (root == NULL) {
        printf(" cay cua ban chua co gia tri o goc\n hay khoi tao gia tri gioc cho cay:");
        scanf("%d", &value);
        getchar();
        root = creatNode(value);
    } else {
        do {
            printf("moi ban nhap vao gia tri cua node muon tao nhanh\n");
            scanf("%d", &value);
            getchar();
            Node *find = findNode(*root, value);
            if (find == NULL) {
                printf("Node ban tim khong co trong cay\n");
            } else {
                do {
                    printf(" moi ban nhap nhanh muon tao node moi (1 = left || 2 = right )\n");
                    scanf("%d", &value);
                    getchar();
                    if (value == 1) {
                        printf("moi ban nhap gia tri cua Node ben trai\n");
                        scanf("%d", &value);
                        getchar();
                        find->left = creatNode(value);
                        break;
                    } else if (value == -1) {
                        printf("moi ban nhap gia tri cua Node ben phai\n");
                        scanf("%d", &value);
                        getchar();
                        find->right = creatNode(value);
                        break;
                    } else {
                        printf("moi ban nhap lai \n");
                    }
                } while (1);
                break;
            }
        }while (1);
    }
}


void findLever (Node* root) {


    
}