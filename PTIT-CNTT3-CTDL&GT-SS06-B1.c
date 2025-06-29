#include <stdio.h>

void convertToBinary(int n) {
    if (n == 0) return;

    convertToBinary(n / 2); // chia dần cho 2
    printf("%d", n % 2);
        // in phần dư (bit)
}

int main() {
    int num;
    printf("Nhap so nguyen: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("0");
    } else {
        printf("Nhi phan: ");
        convertToBinary(num);
    }

    return 0;
}
