//
// Created by admin on 6/26/2025.
//
#include <stdio.h>

// Hàm đệ quy đếm số cách leo cầu thang n bậc
int countWays(int n) {
    if (n == 0)
        return 1; // Đã leo xong, 1 cách duy nhất
    if (n == 1)
        return 1; // Chỉ có 1 cách leo 1 bậc

    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n;
    printf("Nhap so bac cau thang: ");
    scanf("%d", &n);

    if (n < 0) {
        return 1;
    } else {
        int ways = countWays(n);
        printf(" %d\n", ways);
    }

    return 0;
}
