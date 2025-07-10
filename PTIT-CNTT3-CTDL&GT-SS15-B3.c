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


int main() {
    // Tạo hàng đợi trống
    Queue q1 = createQueue(5);
    printQueueInfo(q1);

    // Kiểm tra trống
    if (isEmpty(q1)) {
        printf("true\n");
    } else {
        printf("false\n");
    }






    free(q1.array);


    return 0;
}
