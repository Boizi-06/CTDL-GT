#include <stdio.h>

void quickSort(int *arr, int low, int high, int f) {
    if (low >= high) {
        return;
    }

    int pivot = arr[high];
    int i = low - 1;

    if (f == 0) {
        // Lần đầu: tách chẵn - lẻ
        for (int j = low; j < high; j++) {
            if (arr[j] % 2 == 0) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pivot_index = i + 1;

        // Gọi đệ quy 2 bên, tăng f lên 1
        quickSort(arr, low, pivot_index - 1, f + 1);
        quickSort(arr, pivot_index + 1, high, f + 1);
    } else {
        // Các lần sau: sort riêng
        for (int j = low; j < high; j++) {
            if (arr[low] % 2 == 0) {
                // Chẵn → tăng dần
                if (arr[j] < pivot) {
                    i++;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            } else {
                // Lẻ → giảm dần
                if (arr[j] > pivot) {
                    i++;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pivot_index = i + 1;

        quickSort(arr, low, pivot_index - 1, f);
        quickSort(arr, pivot_index + 1, high, f);
    }
}

int main() {
    int arr[] = {6, 4, 3, 2, 1, 5, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1, 0);

    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }

    return 0;
}
