//
// Created by admin on 7/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node của danh sách liên kết
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Hàm tạo Node mới
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm cạnh vào danh sách kề
void addEdge(Node** graph, int u, int v) {
    // Thêm v vào danh sách của u
    Node* nodeV = createNode(v);
    nodeV->next = graph[u];
    graph[u] = nodeV;

    // Thêm u vào danh sách của v (vì đồ thị vô hướng)
    Node* nodeU = createNode(u);
    nodeU->next = graph[v];
    graph[v] = nodeU;
}

// Hàm in danh sách kề
void printGraph(Node** graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Khởi tạo mảng danh sách kề
    Node** graph = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    int u, v;
    while (scanf("%d %d", &u, &v) != EOF) {
        addEdge(graph, u, v);
    }

    printGraph(graph, n);

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);

    return 0;
}
