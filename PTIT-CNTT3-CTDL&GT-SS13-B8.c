//
// Created by admin on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Định nghĩa stack cho số nguyên
typedef struct {
    int *arr;
    int top;
    int maxSize;
} Stack;

// Khởi tạo stack
Stack createStack(int maxSize) {
    Stack s;
    s.arr = (int *)malloc(maxSize * sizeof(int));
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}

// Push
void push(Stack *s, int value) {
    s->top++;
    s->arr[s->top] = value;
}

// Pop
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack rỗng!\n");
        return 0;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
}

// Hàm tính giá trị postfix
int evaluatePostfix(char expr[]) {
    int len = strlen(expr);
    Stack s = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        // Nếu là chữ số
        if (isdigit(c)) {
            push(&s, c - '0'); // Convert char số sang int
        }
        // Nếu là toán tử
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = pop(&s);
            int a = pop(&s);
            int res = 0;

            switch (c) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push(&s, res);
        }
    }

    int finalResult = pop(&s);
    free(s.arr);
    return finalResult;
}

int main() {
    char expr[1000];

    printf("Nhập biểu thức postfix: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0'; // Xóa newline

    printf("\"%s\"\n", expr);

    int result = evaluatePostfix(expr);
    printf("%d\n", result);

    return 0;
}
