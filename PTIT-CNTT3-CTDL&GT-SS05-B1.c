//
// Created by admin on 6/25/2025.
//
#include <stdio.h>
#include <stdlib.h>



void prinNumber (int n,int i) {
    if (i >n) {
        return ;
    }
    printf("%d",i);
    prinNumber(n,i+1);
}

int main () {
    int n;
    scanf("%d",&n);

    prinNumber(n,1);


    return 0;
}

