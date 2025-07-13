#include <stdio.h>
#include <stdlib.h>

// Cấu trúc phần tử Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cấu trúc hàng đợi
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Hàm khởi tạo hàng đợi
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Hàm tạo một node mới với dữ liệu do người dùng nhập
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Input data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Khoi tao hang doi
    Queue* myQueue = createQueue();

    // Tao node moi
    Node* node = createNode();

    // In ra data cua node vua tao
    printf("Data : %d\n", node->data);

    // Giai phong bo nho
    free(node);
    free(myQueue);

    return 0;
}
