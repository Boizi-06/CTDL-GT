//
// Created by admin on 7/23/2025.
//
//
// Created by admin on 7/23/2025.
//
#include <stdio.h>

#define SIZE 4
char labels[SIZE] = {'A','B','C','D'};
// Hàm in ma trận
void printMatrix(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf(" %c", labels[i]);
        for (int j = 0; j < SIZE; j++) {
            printf(" %d", graph[i][j]);
        }
        printf("\n");
    }
}

// Hàm thêm cạnh giữa 2 node trong đồ thị vô hướng
void addEdge(int graph[SIZE][SIZE], int node1, int node2) {
    if (node1 >= 0 && node1 < SIZE && node2 >= 0 && node2 < SIZE) {
        graph[node1][node2] = 1;
        graph[node2][node1] = 1; // Vì là đồ thị vô hướng
    }
}

int main() {
    // Khởi tạo ma trận 3x3 toàn 0 (chưa có cạnh nào)
    int graph[SIZE][SIZE] = {0};

    printf("Ma trận ban đầu:\n");
    printMatrix(graph);

    // Thêm cạnh giữa node 1 và 2 (tức là đỉnh số 1 và 2, tính từ 0)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("\nMa trận sau khi thêm cạnh giữa node 1 và 2:\n");
    printMatrix(graph);

    return 0;
}

