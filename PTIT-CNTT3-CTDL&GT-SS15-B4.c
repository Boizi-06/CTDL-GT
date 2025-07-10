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


void viewQueue(Queue q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }

    // In từng phần tử theo thứ tự từ front đến rear
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d\n", q.array[i]);
    }
}


int main() {

    printf("\n");


    Queue q2 = createQueue(5);
    q2.rear = 2;
    q2.array[0] = 1;
    q2.array[1] = 2;
    q2.array[2] = 5;
    printQueueInfo(q2);
    viewQueue(q2);

    // Giải phóng bộ nhớ

    free(q2.array);

    return 0;
}
