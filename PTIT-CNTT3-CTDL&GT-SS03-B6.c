//
// Created by admin on 6/19/2025.

#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    scanf("%d",&n);
    if (n<0) {
        return 0;
    }
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);

    }
    int m;
    scanf("%d",&m);
    if (m > 0) {
        int *temp = (int *) realloc(arr,n+m* sizeof(int));
        if (temp == NULL) {
            free(arr);
            return 0;
        }
        arr= temp;
        for (int i = 0; i < m; ++i) {
            scanf("%d",&arr[n+i]);
        }
        n+=m;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d",arr[i]);
    }
    free(arr);

    return 0;
}