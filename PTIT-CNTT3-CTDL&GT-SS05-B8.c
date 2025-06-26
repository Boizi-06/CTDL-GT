//
// Created by admin on 6/25/2025.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm kiểm tra chuỗi có phải toàn chữ số (hoặc dấu trừ ở đầu)
int isValid(char str[]) {
    int i = 0;
    if (str[0] == '-') i = 1; // bỏ qua dấu trừ nếu có
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// Hàm đệ quy chuyển chuỗi thành số nguyên
int stringToInt(char str[], int n) {
    if (n == 1)
        return str[0] - '0';
    return stringToInt(str, n - 1) * 10 + (str[n - 1] - '0');
}

int main() {
    char str[100];
    printf("nhap ky tu so: ");
    scanf("%s", str);

    if (!isValid(str)) {
        printf("ennor input\n");
        return 0;
    }

    int isNegative = 0;
    int start = 0;

    if (str[0] == '-') {
        isNegative = 1;
        start = 1;
    }

    int result = stringToInt(str + start, strlen(str) - start);
    if (isNegative) result = -result;

    printf("%d\n", result);

    return 0;
}
