#include <stdio.h>


int main () {
    int n;
    printf("nhap so phan tu cua mang");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i<n; i++) {
        printf("nhap phan tu thu %d :",i+1);
        scanf("%d",&arr[i]);
    }
    int maxCount = 0;
    int number = 0;
    for (int i = 0; i<n; i++) {
        int count = 0;

        for (int j = 0 ; j<n ; j++) {
            if (arr[i]==arr[j]) {
                count++;

            }
        }
        if (count > maxCount) {
            maxCount = count;
            number = arr[i];
        }

    }
    printf("phan tu %d xuat hien %d lan " , number , maxCount);
    return 0;
}