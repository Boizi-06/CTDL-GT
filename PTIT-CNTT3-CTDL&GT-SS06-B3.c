#include <stdio.h>

// Hàm đệ quy tính tổng các chữ số của n
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So nhap vao khong hop le!\n");
        return 1;
    }

    int tong = sumOfDigits(n);
    printf("Tong cac chu so cua %d la: %d\n", n, tong);

    return 0;
}
