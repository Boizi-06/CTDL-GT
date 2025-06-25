#include <stdio.h>


int binarySearch(int arr[], int left, int right, int x) {
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;

    if (arr[mid] == x) {
        return mid;
    } else if (arr[mid] > x) {
        return binarySearch(arr, left, mid - 1, x);
    } else {
        return binarySearch(arr, mid + 1, right, x);
    }
}


int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Nhap so can tim: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result != -1) {
        printf("Tim thay %d tai vi tri %d\n", x, result);
    } else {
        printf("Khong tim thay %d trong mang\n", x);
    }

    return 0;
}
