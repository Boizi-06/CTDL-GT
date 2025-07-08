//
// Created by admin on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc stack
typedef struct {
    int *arr;
    int top;
    int maxSize;
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

// Hàm in mảng
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Hàm đảo ngược mảng bằng stack
void reverseArray(int arr[], int n) {
    Stack s = createStack(n);

    // Đưa tất cả phần tử vào stack
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }

    // Lấy phần tử ra từ stack để gán lại cho mảng
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }

    // Giải phóng bộ nhớ stack
    free(s.arr);
}

int main() {
    int n;
    printf("Nhập số phần tử: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhập giá trị từng phần tử:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Mảng ban đầu:\n");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Mảng sau khi đảo ngược:\n");
    printArray(arr, n);

    return 0;
}
