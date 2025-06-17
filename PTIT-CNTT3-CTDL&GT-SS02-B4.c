#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;


    printf("Nhap so luong phan tu n (0 < n <= 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le.\n");
        return 0;
    }


    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho.\n");
        return 1;
    }


    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    int pos, val;
    printf("Nhap vi tri muon sua (0-%d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le.\n");
        free(arr);
        return 1;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &val);


    arr[pos] = val;


    printf("Mang sau khi cap nhat:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(",");
    }



    free(arr);
    return 0;
}
