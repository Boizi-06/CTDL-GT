//
// Created by admin on 7/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc Node cho danh sách liên kết
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

// Hàm thêm đỉnh vào danh sách kề
void addToList(Node** graph, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;
}

// Hàm chuyển ma trận kề sang danh sách kề
void convertMatrixToList(int n, int matrix[MAX][MAX], Node* graph[MAX]) {
    for (int i = 0; i < n; i++) {
        graph[i] = NULL; // Khởi tạo danh sách rỗng
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                addToList(graph, i, j);
            }
        }
    }
}

// Hàm in danh sách kề
void printGraph(Node* graph[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

// Giải phóng bộ nhớ
void freeGraph(Node* graph[MAX], int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];
    Node* graph[MAX];

    scanf("%d", &n);
    if (n <= 0 || n >= 100) {
        printf("So dinh khong hop le\n");
        return 1;
    }

    // Nhập ma trận kề
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Chuyển sang danh sách kề
    convertMatrixToList(n, matrix, graph);

    // In danh sách kề
    printGraph(graph, n);

    // Giải phóng bộ nhớ
    freeGraph(graph, n);

    return 0;
}
