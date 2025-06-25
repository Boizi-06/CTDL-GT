#include <stdio.h>


int timKiemDeQuy(int arr[], int n, int x, int index) {
    if (index >= n) return -1;
    if (arr[index] == x) return index;
    return timKiemDeQuy(arr, n, x, index + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Nhap so can tim: ");
    scanf("%d", &x);

    int viTri = timKiemDeQuy(arr, n, x, 0);

    if (viTri != -1) {
        printf("Tim thay %d tai vi tri %d.\n", x, viTri);
    } else {
        printf("Khong tim thay %d trong mang.\n", x);
    }

    return 0;
}
