//
// Created by admin on 6/17/2025.


#include <stdio.h>

int main () {
    int n;
    scanf("%d",&n);
    if (n<0||n>100){return 0;}

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    int pos;
    scanf("%d",&pos);
    if (pos<0||pos > n-1) {return 0;}

    for (int i = pos; i < n-1; ++i) {
        int temp = arr[i];
        arr[i]=arr[i+1];
        arr[i+1]= temp;

    }
     n-=1;

    for (int i = 0; i < n; ++i) {
        printf("%d",arr[i]);
    }




    return 0;


}