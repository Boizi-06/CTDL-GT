//
// Created by admin on 7/10/2025.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;


Queue createQueue(int maxSize) {
    Queue q;
    q.array = (int *)malloc(maxSize * sizeof(int));
    q.front = 0;
    q.rear = -1;
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


int isEmpty(Queue q) {
    if (q.rear < q.front) {
        return 1; // true
    } else {
        return 0; // false
    }
}


int dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("queue is empty\n");
        return -1; // Trả về -1 để biểu thị không có phần tử
    }

    int value = q->array[q->front]; // Lấy giá trị ở đầu
    q->front++;                     // Tăng front lên

    return value;                   // Trả về giá trị lấy ra
}


int main() {

    printf("\n");

    // Test case 2: Hàng đợi có phần tử
    Queue q2 = createQueue(5);
    q2.rear = 2;
    q2.array[0] = 1;
    q2.array[1] = 2;
    q2.array[2] = 5;
    printQueueInfo(q2);

    int val2 = dequeue(&q2);
    if (val2 != -1) {
        printf("return value = %d;\n", val2);
        printQueueInfo(q2);
    }

    // Giải phóng bộ nhớ

    free(q2.array);

    return 0;
}

