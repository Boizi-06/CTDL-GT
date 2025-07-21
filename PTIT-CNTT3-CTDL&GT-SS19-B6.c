//
// Created by admin on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// -------------------- Cây nhị phân --------------------
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// -------------------- Queue bằng mảng --------------------
typedef struct {
    Node* data[MAX]; // Mảng chứa con trỏ tới node
    int front;
    int rear;
} Queue;

// Khởi tạo queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue q) {
    return q.front > q.rear;
}

int isFull(Queue q) {
    return q.rear == MAX - 1;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue* q, Node* value) {
    if (isFull(*q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

// Lấy phần tử ra khỏi hàng đợi
Node* dequeue(Queue* q) {
    if (isEmpty(*q)) {
        return NULL;
    }
    return q->data[q->front++];
}

// -------------------- Tìm kiếm BFS --------------------
int searchLevel(Node* root, int target) {
    if (root == NULL) return -1;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int level = 0;

    while (!isEmpty(q)) {
        int count = q.rear - q.front + 1;

        while (count--) {
            Node* curr = dequeue(&q);
            if (curr->data == target) {
                printf("Tim thay %d o tang %d\n", target, level);
                return level;
            }

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }

        level++;
    }

    return -1;
}


int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int level = searchLevel(root, x);
    if (level == -1) {
        printf("Khong tim thay %d trong cay.\n", x);
    }

    return 0;
}

