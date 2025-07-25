//
// Created by admin on 7/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, v;
    int graph[MAX][MAX] = {0};  // Ma trận kề khởi tạo toàn 0

    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    if (n <= 0 || v < 0 || n >= 100 || v >= 100) {
        printf("Gia tri khong hop le.\n");
        return 1;
    }

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        graph[u][w] = 1;
        graph[w][u] = 1; // Vì đồ thị vô hướng
    }

    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("Dinh khong ton tai.\n");
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (graph[k][i] == 1) {
            count++;
        }
    }

    printf("So dinh ke voi %d la: %d\n", k, count);

    return 0;
}
