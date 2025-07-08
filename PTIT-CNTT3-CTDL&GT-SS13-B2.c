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

int main() {
    Stack s = createStack(5);

    printf("Nhập các phần tử:\n");
    for (int i = 0; i < 5; i++) {
        int value;
        scanf("%d", &value);
        push(&s, value);
    }

    // In ra thông tin stack
    printf("\nstack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.arr[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s.top);
    printf("    cap: %d\n", s.maxSize);
    printf("}\n");

    // Giải phóng bộ nhớ
    free(s.arr);

    return 0;
}
