#include <stdio.h>

int fibonacci(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return fibonacci(k - 1) + fibonacci(k - 2);
}

// Hàm đệ quy in n số Fibonacci theo thứ tự ngược lại
void printFibonacciReverse(int n) {
    if (n == 0) return;
    printf("%d ", fibonacci(n - 1));
    printFibonacciReverse(n - 1);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n phai la so nguyen duong!\n");
        return 1;
    }

    printf("%d so Fibonacci dau tien (in nguoc):\n", n);
    printFibonacciReverse(n); // gọi hàm in ngược

    return 0;
}
