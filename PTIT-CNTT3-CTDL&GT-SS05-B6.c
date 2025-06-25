//
// Created by admin on 6/25/2025.
//Xây dựng chương trình yêu cầu người dùng nhập vào hai số nguyên dương bất kỳ firstNum và secondNum.

//Sử dụng đệ quy, tính tổng từ firstNum đến secondNum và in kết quả ra màn hình

#include <stdio.h>

int tinhTong (int firstNum, int secondNum,int sum) {
    if (firstNum > secondNum) {
        return sum;
    }
    sum+=firstNum;
    return tinhTong(firstNum +1,secondNum,sum);

}

int main () {
    int n1,n2;


    scanf("%d",&n1);
    scanf("%d",&n2);
    if (n1<0||n2<0||n1>n2) {
        return 0;
    }

    printf("%d",tinhTong(n1,n2,0));



    return 0;
}
