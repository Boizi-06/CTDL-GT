//
// Created by admin on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n,num,count=0;
    scanf("%d",&n);
    if (n<0) {return 0;}
    int *arr = (int*) calloc(n,sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&num);

    for (int i = 0; i < n; ++i) {
        if (arr[i]==num) {
            printf("%d,",i);
        }else {
            count++;
        }

    }
    if (count == n) {
        printf("phan tu ko co trong mang");
    }



    return 0;

}


