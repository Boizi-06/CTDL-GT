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

// Hàm DFS
void DFS(int v, Node* adjList[], int visited[]) {
    printf("%d ", v);
    visited[v] = 1;

    Node* temp = adjList[v];
    while (temp != NULL) {
        int u = temp->vertex;
        if (!visited[u]) {
            DFS(u, adjList, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int v, e;
    Node* adjList[MAX] = {NULL};  // Danh sách kề
    int visited[MAX] = {0};       // Đánh dấu đỉnh đã thăm

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
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(start, adjList, visited);
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
