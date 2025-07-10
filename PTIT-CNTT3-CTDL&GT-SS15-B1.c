//
// Created by admin on 7/10/2025.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;     // Mảng chứa các phần tử
    int front;      // Chỉ số đầu (front)
    int rear;       // Chỉ số cuối (rear)
    int capacity;   // Số phần tử tối đa
} Queue;

// -------------------------
// Hàm khởi tạo hàng đợi
// -------------------------
Queue createQueue(int maxSize) {
    Queue q;                             // Tạo biến hàng đợi
    q.array = (int *)malloc(maxSize * sizeof(int)); // Cấp phát động mảng với kích thước maxSize
    q.front = 0;                         // Chỉ số đầu tiên
    q.rear = -1;                         // rear = -1 nghĩa là hàng đợi trống
    q.capacity = maxSize;               // Gán số phần tử tối đa
    return q;                           // Trả về hàng đợi
}


// Hàm kiểm tra in ra thông tin hàng đợi

void printQueueInfo(Queue q) {
    printf("queue = {\n");
    printf("   array = [");
    for (int i = 0; i <= q.rear; i++) {
        printf("%d", q.array[i]);
        if (i != q.rear) printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", q.front);
    printf("   rear = %d,\n", q.rear);
    printf("   capacity = %d\n", q.capacity);
    printf("}\n");
}


int main() {
    int maxSize;
    printf("Nhập số phần tử tối đa của hàng đợi: ");
    scanf("%d", &maxSize);

    Queue q = createQueue(maxSize);


    printQueueInfo(q);


    free(q.array);

    return 0;
}
