#include <stdio.h>
#include <stdlib.h>

// Cau truc Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cau truc Queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Ham tao queue rong
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Ham tao node (nguoi dung nhap data)
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Input a number: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

// Ham them node vao queue
void enqueue(Queue* q) {
    Node* newNode = createNode();
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Ham in queue
void printQueue(Queue* q) {
    Node* tmp = q->front;
    printf("queue = {\n");
    printf("  front->");
    while (tmp != NULL) {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");

    printf("  rear->");
    if (q->rear != NULL) {
        printf("%d->NULL\n", q->rear->data);
    } else {
        printf("NULL\n");
    }
    printf("}\n\n");
}

// Ham xem phan tu dau hang doi
void peek(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n\n");
    } else {
        printf("%d\n\n", q->front->data);
    }
}

// Ham main
int main() {
    Queue* q = createQueue();

    // In queue ban dau
    printQueue(q);
    peek(q);

    // Them phan tu vao queue
    enqueue(q);
    enqueue(q);
    enqueue(q);

    printQueue(q);
    peek(q);

    // Giai phong bo nho
    Node* tmp;
    while (q->front != NULL) {
        tmp = q->front;
        q->front = q->front->next;
        free(tmp);
    }
    free(q);

    return 0;
}
