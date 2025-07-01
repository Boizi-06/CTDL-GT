
#include <stdio.h>

// Hàm sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int n,int x) {

    int sum1,sum2;


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (x > arr[j]) {
                sum1 = x - arr[j];
            } else {
                sum1 = arr[j]-x;
            }

            if (x > arr[j+1]){
                sum2 = x - arr[j+1];
            } else {
                sum2 = arr[j+1]-x;
            }
            if (sum1 > sum2) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    // Gọi hàm sắp xếp
    bubbleSort(arr, n,7);

    printf("after: ");
    printArray(arr, n);

    return 0;
}
