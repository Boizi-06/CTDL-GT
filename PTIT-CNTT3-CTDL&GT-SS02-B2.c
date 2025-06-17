//
// Created by admin on 6/17/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main () {

    int n;
    scanf("%d",&n);
    if (n<0||n>100) {
        return 0;
    }

    int arr[n];
    for (int i = 0; i <n; i++) {
        scanf("%d",&arr[i]);
    }
    int value;
    scanf("%d",&value);
    if (value < 0 || value > 100) {return 0;}
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (value==arr[i]) {

            count ++;
        }
    }
    printf("%d",count);

    return  0 ;
}

