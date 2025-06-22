//
// Created by admin on 6/20/2025.
//

#include <stdio.h>
#include <stdlib.h>


int main () {
    int n;
    scanf("%d",&n);
    if (n<0) {
        return 0;
    }
    int *arr = (int *)calloc(n,sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    int count=0;
    for (int i = 0; i < n/2; ++i) {
        if (arr[i]==arr[n-1-i]) {

            printf("cap doi xung : (%d,%d)\n",arr[i],arr[n-1-i]);
        } else {
            count++;
        }


    }
    if (count==n/2) {
        printf("ko cao phan tu doi xung");
    }







    return 0;
}