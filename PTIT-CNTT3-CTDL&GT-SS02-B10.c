#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        int daXuatHien = 0;


        for (int k = 0; k < i; ++k) {
            if (arr[i] == arr[k]) {
                daXuatHien = 1;
                break;
            }
        }

        if (daXuatHien==1){continue;}

        int solan = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[i] == arr[j]) {
                solan++;
            }
        }

        printf("Phan tu %d xuat hien %d lan\n", arr[i], solan);
    }

    return 0;
}
