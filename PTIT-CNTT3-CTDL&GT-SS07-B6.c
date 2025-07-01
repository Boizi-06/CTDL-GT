#include <stdio.h>

// Hàm merge để trộn hai mảng con đã sắp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // số phần tử mảng trái
    int n2 = right - mid;    // số phần tử mảng phải

    // Tạo mảng tạm
    int L[n1], R[n2];

    // Copy dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Trộn 2 mảng L và R vào arr
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy các phần tử còn lại của L (nếu có)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy các phần tử còn lại của R (nếu có)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm merge sort chính (đệ quy)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Đệ quy sắp xếp 2 nửa
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn 2 nửa
        merge(arr, left, mid, right);
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Hàm main
int main() {
    int arr[] = {8, 3, 7, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("After: ");
    printArray(arr, n);

    return 0;
}
