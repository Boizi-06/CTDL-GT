#include <stdio.h>

// Hàm sắp xếp chọn (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        // Tìm chỉ số phần tử nhỏ nhất trong đoạn chưa sắp xếp
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của đoạn chưa sắp xếp
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    // Nhập số lượng phần tử
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    int arr[n];
    // Nhập các phần tử của mảng
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("before: ");
    printArray(arr, n);

    // Gọi hàm sắp xếp chọn
    selectionSort(arr, n);

    printf("after: ");
    printArray(arr, n);

    return 0;
}
