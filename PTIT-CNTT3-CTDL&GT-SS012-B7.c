//
// Created by admin on 7/6/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* createNode(int value);
void printList(node* head);
void sortList(node* head);

int main() {
    int n, value;
    node *head = NULL, *tail = NULL;

    printf("Nhap so luong node: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Nhap gia tri node thu %d: ", i);
        scanf("%d", &value);

        node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("\nDanh sach truoc khi sap xep:\n");
    printList(head);

    sortList(head);

    printf("\nDanh sach sau khi sap xep tang dan:\n");
    printList(head);

    return 0;
}

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(node* head) {
    node* current = head;
    printf("NULL->");
    while (current != NULL) {
        printf("%d<->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void sortList(node* head) {
    if (head == NULL) return;



    node* i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
