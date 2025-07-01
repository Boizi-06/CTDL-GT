//
// Created by admin on 6/30/2025.
//quick sort

#include <stdio.h>


void quickSort(int *arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            // Swap arr[i] và arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Đưa pivot vào vị trí chính
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    int pivot_index = i + 1;

    // Gọi đệ quy 2 bên
    quickSort(arr, low, pivot_index - 1);
    quickSort(arr, pivot_index + 1, high);
}

int main () {
    int arr[] = {6,4,3,2,1,5,9,0};

    quickSort(&arr,0,7);
    for (int j =0;j < 8;j++) {
        printf("%d ",arr[j]);
    }

    return 0;
}