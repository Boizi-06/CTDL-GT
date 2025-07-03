//
// Created by admin on 7/3/2025.
//
//
// Created by admin on 7/3/2025.
//
//
// Created by admin on 7/3/2025.
//
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

void deleteAllNodes(node** head, int value) {
    while (*head != NULL && (*head)->data == value) {
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if (*head == NULL) return;

    node* curent = *head;
    while (curent->next != NULL) {
        if (curent->next->data == value) {
            node* temp = curent->next;
            curent->next = curent->next->next;
            free(temp);
        } else {
            curent = curent->next;
        }
    }
}
void findNode (node* head) {
    node* curent = head;
    int i =0;
    while (curent != NULL) {
        curent = curent ->next;
        i++;
    }
    node* curent2 = head;
    int rs = i /2;
    int k=0;
    while (k<rs) {
        curent2 = curent2->next;
        k++;


    }
    k++;
    printf("\n node %d : %d", k, curent2->data);

}
void sortNode(node* head) {
    if (head == NULL || head->next == NULL)
        return;

    node* i;
    node* j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Hoán đổi giá trị data
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
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
    printf("\n nhap gia tri b muon xoa");
    int k;
    printf("\n");
    scanf("%d",&k);
    deleteAllNodes(&head,k);
    printf("\n");
    printNode(head);
    findNode(head);
    sortNode(head);
    printf("\n");
    printNode(head);
    return 0;
}//
// Created by admin on 7/3/2025.
//
