//
// Created by admin on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>
//
// Created by admin on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    scanf("%d",&n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }

    int max = arr[0];

    for (int i = 0; i < n; ++i) {
        if (max > arr[i]) {
            max = arr[i];
        }

    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] == max) {
            printf("%d",i);
        }
    }
    free(arr);
    return 0;



}
