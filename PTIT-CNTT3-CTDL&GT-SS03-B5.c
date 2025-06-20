//
// Created by admin on 6/19/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n , m;
    scanf("%d",&n);
    scanf("%d",&m);

    if (n<1||m<1) {
        return 0;
    }
    int **arr = (int**) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int*) malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; ++i) {
        for (int j =0 ;j < m ; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j =0 ;j < m ; j++) {
           printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int tc=0,tp=0;
    for (int i = 0; i < n; ++i) {
        for (int j =0 ;j < m ; j++) {
           if (i==j) {
               tc+=arr[i][j];
           }
            if (i+j == n-1) {
               tp += arr[i][j];
           }
        }
    }
    printf("tong duong cheo chinh la %d \n tong duong cheo phu la %d \n",tc,tp);



    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}