//
// Created by admin on 7/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Khởi tạo đồ thị với ma trận kề n x n toàn 0
int** createGraph(int n) {
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)calloc(n, sizeof(int));  // cấp phát và gán 0
    }
    return graph;
}

// Hàm thêm cạnh giữa hai đỉnh u và v
void addEdge(int** graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;  // vì đồ thị vô hướng nên cần gán đối xứng
}

// Hàm in ma trận kề
void printGraph(int** graph, int n) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Giải phóng bộ nhớ
void freeGraph(int** graph, int n) {
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    int n;
    printf("Nhap so luong dinh: ");
    scanf("%d", &n);

    int** graph = createGraph(n);

    int soCanh;
    printf("Nhap so luong canh: ");
    scanf("%d", &soCanh);

    printf("Nhap cac canh (u v):\n");
    for (int i = 0; i < soCanh; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph, n);
    freeGraph(graph, n);

    return 0;
}
