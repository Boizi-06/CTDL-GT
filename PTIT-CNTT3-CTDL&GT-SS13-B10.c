//
// Created by admin on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack cho toán tử
typedef struct {
    char arr[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    s->arr[++s->top] = c;
}

char pop(Stack *s) {
    return s->arr[s->top--];
}

char peek(Stack *s) {
    return s->arr[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

char *infixToPostfix(char expr[]) {
    Stack s;
    s.top = -1;
    char *output = (char *)malloc(strlen(expr) * 2); // dự phòng nhiều ký tự
    int k = 0;

    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        if (isspace(c)) continue; // Bỏ khoảng trắng

        if (isalnum(c)) {
            output[k++] = c;
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                output[k++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) == '(') {
                pop(&s); // Bỏ dấu '('
            }
        }
        else { // toán tử
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                output[k++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (!isEmpty(&s)) {
        output[k++] = pop(&s);
    }

    output[k] = '\0';
    return output;
}

int main() {
    char expr[100];

    printf("Nhập biểu thức infix: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0'; // Xóa newline

    char *postfix = infixToPostfix(expr);
    printf("Biểu thức postfix: %s\n", postfix);

    free(postfix);
    return 0;
}
