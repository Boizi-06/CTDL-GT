//
// Created by admin on 7/9/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo Node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Cấu trúc Stack
typedef struct Stack {
    Node* top;
} Stack;

// Hàm khởi tạo Stack
Stack createStack() {
    Stack s;
    s.top = NULL;
    return s;
}

// Hàm main khởi tạo stack
int main() {
    Stack myStack = createStack();
    printf("Stack đã được khởi tạo. Top hiện tại: %p\n", myStack.top);
    return 0;
}
