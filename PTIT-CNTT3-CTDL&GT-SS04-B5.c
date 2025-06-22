//
// Created by admin on 6/20/2025.
//



#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    scanf("%d",&n);

    if (n < 0) {
        return 0;
    }
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n -1; ++i) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
        }
    }
    int num;
    scanf("%d",&num);
    int left = 0, right = n - 1;
    int found = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == num) {
            printf("Phan tu co trong mang\n");
            found = 1;
            break;
        } else if (arr[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Phan tu khong co trong mang\n");
    }



    return 0;
}