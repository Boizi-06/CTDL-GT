//
// Created by admin on 6/17/2025.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {

    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i <n; i++) {
        scanf("%d",&arr[i]);
    }
    int min = arr[0];
    for (int i = 1; i < n; ++i) {
        if (min<arr[i]) {
            min= arr[i];
        }
    }
    printf("%d",min);

    return  0 ;
}

