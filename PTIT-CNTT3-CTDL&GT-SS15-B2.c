//
// Created by admin on 7/10/2025.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *array;    // Mảng chứa phần tử
    int front;     // Chỉ số đầu
    int rear;      // Chỉ số cuối
    int capacity;  // Sức chứa tối đa
} Queue;


Queue createQueue(int maxSize) {
    Queue q;
    q.array = (int *)malloc(maxSize * sizeof(int));
    q.front = 0;
    q.rear = -1; // Hàng đợi trống
    q.capacity = maxSize;
    return q;
}


void printQueueInfo(Queue q) {
    printf("queue = {\n");
    printf("   array = [");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d", q.array[i]);
        if (i != q.rear) printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", q.front);
    printf("   rear = %d,\n", q.rear);
    printf("   capacity = %d\n", q.capacity);
    printf("}\n");
}


void enqueue(Queue *q) {
    int value;
    printf("Nhập số nguyên: ");
    scanf("%d", &value);

    // Kiểm tra nếu đầy
    if (q->rear + 1 >= q->capacity) {
        printf("queue is full\n");
        return;
    }

    q->rear++;               // Tăng chỉ số cuối
    q->array[q->rear] = value; // Gán giá trị
}


int main() {
    int maxSize;
    printf("Nhập sức chứa tối đa của hàng đợi: ");
    scanf("%d", &maxSize);

    Queue q = createQueue(maxSize);
    printQueueInfo(q);


    for (int i = 0; i < 5; i++) {
        enqueue(&q);
        printQueueInfo(q);
    }


    free(q.array);

    return 0;
}
