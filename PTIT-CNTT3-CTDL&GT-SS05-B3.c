//
// Created by admin on 6/25/2025.
//Xây dựng chương trình yêu cầu người dùng nhập vào một số nguyên dương bất kỳSử dụng đệ quy, tính và in ra giai thừa của số đã nhập

#include <stdio.h>


int  factorial (int n) {
    if (n==0) {
        return 1;
    }
    return n * factorial(n-1);
}


int main () {


    int n;
    scanf("%d",&n);
    if (n < 0) {
        return 0;
    }

    printf("%d",factorial(n));

}
