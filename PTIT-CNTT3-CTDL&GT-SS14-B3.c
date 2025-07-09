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

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    Node* node = createNode(data);
    node->next = stack->head;
    stack->head = node;
}

void show(Stack* stack) {
    Node* node = stack->head;
    if (node == NULL) {
        printf("Ngan xep trong\n");
        return;
    }
    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

int main(void) {
    Stack* stack = createStack();
    for ( int i = 0; i < 5; i++) {
        push(stack, i+1);
    }
    show(stack);
    return 0;
}