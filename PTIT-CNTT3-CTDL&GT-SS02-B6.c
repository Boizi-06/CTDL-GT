//
// Created by admin on 6/17/2025.
//
#include <stdio.h>

int main () {

    int n;
    scanf("%d",&n);
    if (n<0||n>100){return 0;}

    int arr[n];
    for (int i = 0; i <n; i++) {
        scanf("%d",&arr[i]);
    }
    int value,pos;
    scanf("%d",&pos);
    if (pos<0||pos>n-1){return 0;}
    scanf("%d",&value);


    for (int i = n; i > pos; i--) {
        arr[i]=arr[i-1];
    }
    arr[pos]=value;
    n++;
    for (int i = 0; i <n; i++) {
        printf("%d",arr[i]);
    }


    return 0;
}