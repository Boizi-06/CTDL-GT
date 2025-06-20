//
// Created by admin on 6/19/2025.
//
#include <stdio.h>
#include <stdlib.h>

int tinhTongDong(int **arr, int cols, int rowIndex) {
    int sum = 0;
    for (int j = 0; j < cols; ++j) {
        sum += arr[rowIndex][j];
    }
    return sum;
}

int main() {
    int rows, cols;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    if (rows <= 0 || rows >= 1000) {
        printf("So hang khong hop le\n");
        return 0;
    }

    printf("Nhap so cot: ");
    scanf("%d", &cols);
    if (cols <= 0 || cols >= 1000) {
        printf("So cot khong hop le\n");
        return 0;
    }

    // Cấp phát mảng 2 chiều
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    // Nhập mảng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Nhập dòng cần tính
    int k;
    printf("Nhap dong can tinh tong (bat dau tu 0): ");
    scanf("%d", &k);
    if (k < 0 || k >= rows) {
        printf("Hang can tinh khong ton tai\n");
    } else {
        int tong = tinhTongDong(arr, cols, k);
        printf("sum = %d\n", tong);
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
