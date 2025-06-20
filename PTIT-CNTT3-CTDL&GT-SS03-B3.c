//
// Created by admin on 6/19/2025.
//
#include <stdio.h>
#include <stdlib.h>
int main () {
    int n;
    scanf("%d",&n);
    if (n<0) {
        printf("ennor");
        return 0;
    }
    int *arr = ( int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    int sum=0,num=0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            num++;
            sum+=arr[i];
        }

    }

    int tbc = sum / num;
    printf("%d",tbc);
    free(arr);
    return 0;
}