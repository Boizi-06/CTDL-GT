//
// Created by admin on 6/25/2025.
//
//Xây dựng chương trình yêu cầu người dùng nhập vào một chuỗi bất kỳ

//Sử dụng đệ quy, tính tổng từ 1 đến n và in kết quả ra màn hình
#include <stdio.h>
#include <stdlib.h>
int sum(int n ) {
    if (n == 1) {
        return 1;
    }
    return n + sum(n-1);
}

int main () {
    int n;
    scanf("%d",&n);
    if (n < 0) {
        printf("ko hop le ");
        return 0;
    }
    printf("%d",sum(n));

    return 0;
}