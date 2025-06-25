#include <stdio.h>


int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    // Nhập số nguyên dương n
    do {
        printf("Nhap mot so nguyen duong n: ");
        scanf("%d", &n);
    } while (n <= 0);

    int fiboArr[n];


    for (int i = 0; i < n; ++i) {
        fiboArr[i] = fibonacci(i);
    }

    // In kết quả

    for (int i = 0; i < n; ++i) {
        printf("%d ", fiboArr[i]);
    }
    printf("\n");

    return 0;
}
