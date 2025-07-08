//
// Created by admin on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc stack
typedef struct {
    int *arr;      // Mảng chứa phần tử
    int top;       // Chỉ số phần tử trên cùng
    int maxSize;   // Số phần tử tối đa
} Stack;

// Hàm khởi tạo stack
Stack createStack(int maxSize) {
    Stack s;
    s.arr = (int *)malloc(maxSize * sizeof(int));
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}

// Hàm thêm phần tử vào stack
void push(Stack *s, int value) {
    if (s->top >= s->maxSize - 1) {
        printf("Stack đầy, không thể thêm phần tử %d\n", value);
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}

// Hàm lấy phần tử ra khỏi stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    int value = s->arr[s->top];
    s->top--;
    return value;
}

void printStack(Stack s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.arr[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s.top);
    printf("    cap: %d\n", s.maxSize);
    printf("}\n");
}


void viewStack(Stack s) {
    for (int i = s.top; i >= 0; i--) {
        printf("%d\n", s.arr[i]);
    }
}

int main() {
    Stack s = createStack(5);

    printf("Nhập 5 phần tử:\n");
    for (int i = 0; i < 5; i++) {
        int value;
        scanf("%d", &value);
        push(&s, value);
    }

    printStack(s);
    viewStack(s);
    free(s.arr);

    return 0;
}
