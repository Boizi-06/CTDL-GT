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


int isEmpty(Queue q) {
    return q.rear < q.front;
}

void enqueue(Queue *q, int value) {
    if (q->rear + 1 >= q->capacity) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}


int dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue is empty\n");
        return -1; // Trả về -1 nếu rỗng
    }
    int value = q->array[q->front];
    q->front++;
    return value;
}


int checkIncreasingByOne(Queue q) {
    // Nếu có 0 hoặc 1 phần tử => mặc định đúng
    if (q.rear - q.front + 1 <= 1) {
        return 1;
    }

    while (q.front < q.rear) {
        int first = dequeue(&q);
        int second = q.array[q.front];

        if (second - first != 1) {
            return 0; // False
        }
    }
    return 1; // True
}


int main() {
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    Queue q = createQueue(n);

    printf("Nhập dãy số:\n");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    if (checkIncreasingByOne(q)) {
        printf("True\n");
    } else {
        printf("False\n");
    }


    free(q.array);

    return 0;
}
