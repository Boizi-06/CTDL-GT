//
// Created by admin on 6/19/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    if (n<1 || m<1) {
        return 0;
    }
    int **arr = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int *) malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j <m ;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    int min = arr[0][0], max = arr[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j <m ;j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            } else if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    printf("max = %d, min = %d",max,min);
    for (int i= 0 ;i< n ; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}