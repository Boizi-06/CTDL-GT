//
// Created by admin on 7/6/2025.
//
//
// Created by admin on 7/6/2025.
//
//
// Created by admin on 7/6/2025.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

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

void printFromHead(node* head) {
    node* current = head;
    printf("\nNULL->");
    while (current != NULL) {
        printf("%d<->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void printFromTail(node* tail) {
    node* current = tail;
    printf("\nNULL->");
    while (current != NULL) {
        printf("%d<->", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

bool searchNode(node* head, int value) {
    node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}
int getLength(node* head) {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


int main () {
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

    printFromHead(head);
    int length = getLength(head);
    printf("danh sach lien ket co %d phan tu",length);


    return 0;
}