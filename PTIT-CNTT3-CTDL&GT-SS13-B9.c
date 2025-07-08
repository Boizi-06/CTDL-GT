//
// Created by admin on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Định nghĩa Stack cho chuỗi
typedef struct {
    char **arr;  // mảng chứa các chuỗi
    int top;
    int maxSize;
} Stack;

// Hàm khởi tạo stack
Stack createStack(int maxSize) {
    Stack s;
    s.arr = (char **)malloc(maxSize * sizeof(char *));
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}

// Push
void push(Stack *s, char *str) {
    s->top++;
    s->arr[s->top] = strdup(str); // copy chuỗi vào stack
}

// Pop
char *pop(Stack *s) {
    if (s->top == -1) return NULL;
    char *res = s->arr[s->top];
    s->top--;
    return res;
}

// Hàm chuyển postfix sang infix
char *postfixToInfix(char expr[]) {
    int len = strlen(expr);
    Stack s = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (isdigit(c)) {
            // Nếu là chữ số, chuyển thành chuỗi
            char temp[2];
            temp[0] = c;
            temp[1] = '\0';
            push(&s, temp);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            char *op2 = pop(&s);
            char *op1 = pop(&s);

            // Tạo chuỗi mới (op1 operator op2)
            char *newExpr = (char *)malloc(strlen(op1) + strlen(op2) + 4); // ngoặc + toán tử + '\0'
            sprintf(newExpr, "(%s%c%s)", op1, c, op2);

            // Push lại stack
            push(&s, newExpr);


            free(op1);
            free(op2);
        }
    }

    char *result = pop(&s);
    free(s.arr);
    return result;
}

int main() {
    char expr[100];

    printf("Nhập biểu thức postfix: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    char *infix = postfixToInfix(expr);
    printf("Biểu thức infix: %s\n", infix);

    free(infix);
    return 0;
}
