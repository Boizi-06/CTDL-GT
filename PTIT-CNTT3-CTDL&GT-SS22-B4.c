//
// Created by admin on 7/25/2025.
//
#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int matrix[MAX][MAX];
    int edgeCount = 0;

    // Nhập số đỉnh
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

    // Đếm số cạnh (chỉ đếm một chiều để tránh trùng)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                edgeCount++;
            }
        }
    }

    // In kết quả
    printf("%d\n", edgeCount);

    return 0;
}
