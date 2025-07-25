//
// Created by admin on 7/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc Node cho danh sách kề
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Hàng đợi cho BFS
typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

// Hàm tạo Node mới
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Thêm cạnh vào danh sách kề
void addEdge(Node* adjList[], int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

// Hàm khởi tạo hàng đợi
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Kiểm tra hàng đợi rỗng
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Thêm phần tử vào hàng đợi
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Lấy phần tử ra khỏi hàng đợi
int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Hàm BFS
void BFS(int start, Node* adjList[], int visited[]) {
    Queue* q = createQueue();
    enqueue(q, start);
    visited[start] = 1;

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        Node* temp = adjList[current];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                visited[v] = 1;
                enqueue(q, v);
            }
            temp = temp->next;
        }
    }
    free(q);
}

int main() {
    int v, e;
    Node* adjList[MAX] = {NULL};
    int visited[MAX] = {0};

    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    if (v <= 0 || e < 0 || v >= MAX || e >= MAX) {
        printf("Gia tri khong hop le!\n");
        return 1;
    }

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(adjList, u, w);
    }

    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);
    BFS(start, adjList, visited);
    printf("\n");

    // Giải phóng bộ nhớ
    for (int i = 0; i < v; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}

