//
// Created by admin on 7/2/2025.
//
//
// Created by admin on 7/2/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next ;
}node;

node* createNode (int data) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode ->data = data;
    newnode ->next = NULL;
    return newnode;
}
void printNode (node* head) {
    node* curent = head;
    while (curent!= NULL) {
        printf("%d->",curent->data);
        curent=curent->next;
    }
    printf("NULL");
}

void findNode (node* head,int value) {
    node* curent = head;
    while (curent != NULL) {
        if (curent->data == value) {
            printf("true");
            return ;
        }
        curent=curent->next;

    }
    printf("fales");
    return ;

}
int main () {
    int n;
    printf("nhap so luong node muon tao");
    scanf("%d",&n);
    int arr[n];
    printf("nhap gia tri cua cac node \n");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    node* head = createNode(arr[0]);
    node* curent = head;
    for (int i = 1; i < n; ++i) {
        node* newnode = createNode(arr[i]);
        curent->next = newnode;
        curent = newnode;
    }
    printNode(head);

    int value;
    printf("\nnhap data cua node muon tim\n");
    scanf("%d",&value);

    findNode(head,value);
    return 0;
}