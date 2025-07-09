//
// Created by admin on 7/9/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct {
    Node* head;
}Stack;

Node* createNode( int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->head = NULL;
    return newStack;
}

void push(Stack* stack) {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if ( n <=0 ) {
        printf("n khong nguyen duong\n");
        return;
    }
    Node* newNode = createNode(n);
    newNode->next = stack->head;
    stack->head = newNode;
}

void show(Stack* stack) {
    Node* temp = stack->head;
    if ( temp == NULL ) {
        printf("Ngan xep trong\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    Stack* stack = createStack();

    for ( int i = 0; i < 5; i++) {
        push(stack);
    }
    show(stack);
    return 0;
}