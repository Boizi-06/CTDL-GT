//
// Created by admin on 6/19/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("enor!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
