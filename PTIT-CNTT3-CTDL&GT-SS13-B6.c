//
// Created by admin on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Định nghĩa cấu trúc stack
typedef struct {
    char *arr;
    int top;
    int maxSize;
} Stack;

// Hàm khởi tạo stack
Stack createStack(int maxSize) {
    Stack s;
    s.arr = (char *)malloc(maxSize * sizeof(char));
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}

// Hàm thêm phần tử vào stack
void push(Stack *s, char value) {
    if (s->top >= s->maxSize - 1) {
        printf("Stack đầy, không thể thêm phần tử %c\n", value);
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}

// Hàm lấy phần tử ra khỏi stack
char pop(Stack *s) {
    if (s->top == -1) {
        printf("No element in stack\n");
        return '\0';
    }
    char value = s->arr[s->top];
    s->top--;
    return value;
}

// Hàm kiểm tra chuỗi đối xứng
bool isPalindrome(char str[]) {
    int len = strlen(str);
    Stack s = createStack(len);

    // Đưa toàn bộ ký tự vào stack
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // So sánh từng ký tự với phần tử lấy ra từ stack
    for (int i = 0; i < len; i++) {
        char c = pop(&s);
        if (str[i] != c) {
            free(s.arr);
            return false;
        }
    }

    free(s.arr);
    return true;
}

int main() {
    char str[1000];

    printf("Nhập chuỗi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Xóa ký tự newline

    printf("\"%s\"\n", str);

    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
