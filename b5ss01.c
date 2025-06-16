#include <stdio.h>

int main() {
    printf("Hello, World!\n");

    int n;
    printf("Nhap so phan tu cua mang so nguyen: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }


    printf("Mang vua nhap la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\n mang sau khi xap xep la :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    // vì dùng 2 vòng for nên độ phức tạp là On bình phương


    return 0;
}
