#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30
#define MAX_QUEUE 100

// Cau truc hang doi
typedef struct {
    char **array; // Mang chua ten khach
    int front;
    int rear;
    int capacity;
} Queue;

// Tao hang doi
Queue createQueue(int maxSize) {
    Queue q;
    q.array = (char **)malloc(maxSize * sizeof(char *));
    for (int i = 0; i < maxSize; i++) {
        q.array[i] = (char *)malloc((MAX_NAME + 1) * sizeof(char));
    }
    q.front = 0;
    q.rear = -1;
    q.capacity = maxSize;
    return q;
}

// Kiem tra rong
int isEmpty(Queue q) {
    return q.rear < q.front;
}

// Kiem tra day
int isFull(Queue q) {
    return q.rear - q.front + 1 >= q.capacity;
}

// Them khach
void enqueue(Queue *q, char name[]) {
    if (isFull(*q)) {
        printf("Hang doi day, khong them duoc khach moi.\n");
        return;
    }
    q->rear++;
    strcpy(q->array[q->rear], name);
}

// Phuc vu khach
void serve(Queue *q) {
    if (isEmpty(*q)) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Phuc vu khach: %s\n", q->array[q->front]);
    q->front++;
}

// Hien thi danh sach khach
void display(Queue q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d. %s\n", i - q.front + 1, q.array[i]);
    }
}

int main() {
    Queue queueOld = createQueue(MAX_QUEUE);    // Hang doi nguoi gia
    Queue queueNormal = createQueue(MAX_QUEUE); // Hang doi nguoi thuong

    int choice;
    char name[MAX_NAME + 1];
    int age;

    do {
        // Menu
        printf("\n----- Menu -----\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach\n");
        printf("3. Hien thi danh sach khach\n");
        printf("4. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar(); // Doc ky tu '\n'

        switch (choice) {
            case 1:
                printf("Nhap ten khach: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Xoa '\n'

                printf("Nhap tuoi: ");
                scanf("%d", &age);
                getchar(); // Doc '\n'

                if (age >= 60) {
                    enqueue(&queueOld, name); // Them vao queue nguoi gia
                } else {
                    enqueue(&queueNormal, name); // Them vao queue thuong
                }
                break;
            case 2:
                if (!isEmpty(queueOld)) {
                    serve(&queueOld); // Phuc vu nguoi gia truoc
                } else if (!isEmpty(queueNormal)) {
                    serve(&queueNormal); // Neu khong co nguoi gia, phuc vu nguoi thuong
                } else {
                    printf("Khong co khach nao trong hang doi.\n");
                }
                break;
            case 3:
                printf("\nDanh sach nguoi gia:\n");
                display(queueOld);
                printf("\nDanh sach nguoi thuong:\n");
                display(queueNormal);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 4);

    // Giai phong bo nho
    for (int i = 0; i < MAX_QUEUE; i++) {
        free(queueOld.array[i]);
        free(queueNormal.array[i]);
    }
    free(queueOld.array);
    free(queueNormal.array);

    return 0;
}
