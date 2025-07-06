<<<<<<< HEAD
//
// Created by admin on 7/3/2025.
//
//
// Created by admin on 7/3/2025.
//
//
// Created by admin on 7/3/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;


node* createNode (int data) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void printNode ( node* head) {
    node* curent = head;
    while (curent != NULL) {

        printf("%d ->", curent->data);
        curent = curent->next;

    }
    printf("NULL");
}

void insertEnd(node* head,int data) {
    node* curent = head;
    node* newnode = createNode(data);
    while (curent->next != NULL) {
        curent = curent->next;
    }
    curent->next = newnode;

}
void deleteEnd(node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    node* curent = head;
    while (curent->next->next != NULL) {
        curent = curent->next;
    }

    free(curent->next);
    curent->next = NULL;
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
    printf("\nnhap gia tri muon them vao cuoi");
    int data;
    scanf("%d",&data);
    insertEnd(head,data);
    printNode(head);
    deleteEnd(head);
    printf("\n");
    printNode(head);

    return 0;
}//
// Created by admin on 7/3/2025.
//
=======
//
// Created by admin on 7/3/2025.
//
//
// Created by admin on 7/3/2025.
//
//
// Created by admin on 7/3/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;


node* createNode (int data) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void printNode ( node* head) {
    node* curent = head;
    while (curent != NULL) {

        printf("%d ->", curent->data);
        curent = curent->next;

    }
    printf("NULL");
}

void insertEnd(node* head,int data) {
    node* curent = head;
    node* newnode = createNode(data);
    while (curent->next != NULL) {
        curent = curent->next;
    }
    curent->next = newnode;

}
void deleteEnd(node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    node* curent = head;
    while (curent->next->next != NULL) {
        curent = curent->next;
    }

    free(curent->next);
    curent->next = NULL;
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
    printf("\nnhap gia tri muon them vao cuoi");
    int data;
    scanf("%d",&data);
    insertEnd(head,data);
    printNode(head);
    deleteEnd(head);
    printf("\n");
    printNode(head);

    return 0;
}//
// Created by admin on 7/3/2025.
//
>>>>>>> 1c265570270a802fdbeb7a42721c479d9c6ec6a9
