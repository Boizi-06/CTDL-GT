//
// Created by admin on 6/17/2025.



#include <stdio.h>
int main () {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }

    int sum,num1,num2;
    scanf("%d",&sum);

    for (int i = 0; i < n; ++i) {
        if (arr[i]+arr[i+1]==sum) {
            num1 = arr[i];
            num2 = arr[i+1];
            printf("%d , %d",num1,num2);
            return 0;
        }
    }

    printf("khong tim thay");


    return 0;
}