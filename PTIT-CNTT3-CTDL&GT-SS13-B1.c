//
// Created by admin on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *arr;
    int top;
    int maxSize;
} Stack;
Stack createStack(int maxSize) {
    Stack s;
    s.arr = (int *)malloc(maxSize * sizeof(int));
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}
int main() {

    Stack myStack = createStack(5);

    printf("Đã tạo stack với số phần tử tối đa: %d\n", myStack.maxSize);
    printf("Top hiện tại: %d\n", myStack.top);


    free(myStack.arr);

    return 0;
}
