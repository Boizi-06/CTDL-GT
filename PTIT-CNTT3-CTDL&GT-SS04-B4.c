//
// Created by admin on 6/20/2025.
//
//
// Created by admin on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    scanf("%d",&n);
    if (n < 0 ) {
        return 0;
    }

    int *arr = (int *) calloc( n , sizeof(int));

    for (int i = 0; i < n ; ++i) {
        scanf("%d",&arr[i]);
    }
    int num;
    scanf("%d",&num);
    for (int i = n-1  ; i > 0 ; i++) {
        if (num == arr[i]) {
            printf("%d",i);
            break;
        }
    }

    free(arr);
    return 0;
}