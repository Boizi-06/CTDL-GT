#include <stdio.h>
#include <stdlib.h>

// Cấu trúc cho một phần tử trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo phần tử mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Không đủ bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm cạnh vào đồ thị vô hướng
void addEdge(Node* graph[], int start, int end) {
    // Thêm end vào danh sách liên kết của start
    Node* newNode = createNode(end);
    newNode->next = graph[start];
    graph[start] = newNode;

    // Thêm start vào danh sách liên kết của end (vì là đồ thị vô hướng)
    newNode = createNode(start);
    newNode->next = graph[end];
    graph[end] = newNode;
}

// Hàm in đồ thị
void printGraph(Node* graph[], int V) {
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Hàm main demo theo ví dụ bạn cung cấp
int main() {
    int V = 3; // Số đỉnh
    Node* graph[V];

    // Khởi tạo mảng danh sách liên kết rỗng
    for (int i = 0; i < V; i++) {
        graph[i] = NULL;
    }

    // Ví dụ: Thêm cạnh giữa 1 và 2
    addEdge(graph, 1, 2);

    // In đồ thị sau khi thêm
    printf("Sau khi thêm cạnh 1-2:\n");
    printGraph(graph, V);

    // Thêm cạnh giữa 0 và 1
    addEdge(graph, 0, 1);

    // In đồ thị sau khi thêm tiếp
    printf("\nSau khi thêm cạnh 0-1:\n");
    printGraph(graph, V);

    return 0;
}
