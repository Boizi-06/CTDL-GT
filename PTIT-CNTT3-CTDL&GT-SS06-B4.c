
// Created by admin on 6/26/2025.
//

#include <stdio.h>
#include <string.h>
void findNumber (int arr[] , int length , int n,int min , int max) {

    if (n == length) {
        printf("min :%d\n max : %d",min ,max);
        return ;
    }
    if (arr[n] > max) {
        max = arr[n];
    }
    if (arr[n] < min ) {
        min = arr[n];
    }
    findNumber(arr,length,n+1,min,max);
}







int main () {

    int arr [] = {1,2,3,4,5,6,7,8};

    int length = sizeof(arr) / sizeof(arr[0]);


    int max = arr[0],min = arr[0];

    findNumber(arr,length,0,min,max);


    return 0;
}