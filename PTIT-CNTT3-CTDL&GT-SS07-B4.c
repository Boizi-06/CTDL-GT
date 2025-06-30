//
// Created by admin on 6/30/2025.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm sắp xếp ký tự theo thứ tự a-z (dùng thuật toán sắp xếp chèn)
void sortString(char str[]) {
    int i, j;
    char key;
    int n = strlen(str);
    for (i = 1; i < n; i++) {
        key = str[i];
        j = i - 1;

        // Chỉ sắp xếp chữ thường, có thể thêm kiểm tra nếu cần
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
}

int main() {
    char str[1000];

    // Nhập chuỗi
    fgets(str, sizeof(str), stdin);

    // Xóa ký tự '\n' nếu có
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Kiểm tra chuỗi rỗng
    if (strlen(str) == 0) {
        printf("Chuoi khong hop le\n");
        return 0;
    }

    printf("\"%s\"\n", str);

    sortString(str);

    printf("\"%s\"\n", str);

    return 0;
}
