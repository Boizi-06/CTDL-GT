#include <stdio.h>

// Hàm sắp xếp chèn (Insertion Sort)
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Di chuyển các phần tử lớn hơn key sang phải
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    scanf("%d", &n);

    // Kiểm tra điều kiện
    if (n <= 0 || n >= 1000) {
        printf("n khong hop le!\n");
        return 0;
    }

    int arr[1000]; // Khai báo mảng với kích thước tối đa

    // Nhập mảng
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("before: ");
    printArray(arr, n);

    // Gọi hàm sắp xếp
    insertionSort(arr, n);

    printf("after: ");
    printArray(arr, n);

    return 0;
}
