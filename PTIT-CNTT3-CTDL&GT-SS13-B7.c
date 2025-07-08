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
        printf("Stack đầy\n");
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}

// Hàm lấy phần tử ra khỏi stack
char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    char value = s->arr[s->top];
    s->top--;
    return value;
}

// Hàm kiểm tra ngoặc đóng có khớp với ngoặc mở không
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Hàm kiểm tra tính hợp lệ của dấu ngoặc
bool isValidParentheses(char str[]) {
    int len = strlen(str);
    Stack s = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char open = pop(&s);
            if (!isMatching(open, c)) {
                free(s.arr);
                return false;
            }
        }
    }

    bool result = (s.top == -1); // Nếu sau cùng stack rỗng thì hợp lệ

    free(s.arr);
    return result;
}

int main() {
    char expr[1000];

    printf("Nhập biểu thức: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0'; // Xóa newline

    printf("\"%s\"\n", expr);

    if (isValidParentheses(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
