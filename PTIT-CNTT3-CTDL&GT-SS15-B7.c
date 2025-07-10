#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30  // Ten khach toi da 30 ky tu
#define MAX_QUEUE 100 // So khach toi da trong hang doi

// Cau truc hang doi
typedef struct {
    char **array;  // Mang con tro string luu ten khach
    int front;     // Vi tri dau hang doi
    int rear;      // Vi tri cuoi hang doi
    int capacity;  // Suc chua toi da
} Queue;

// Tao hang doi
Queue createQueue(int maxSize) {
    Queue q;
    q.array = (char **)malloc(maxSize * sizeof(char *)); // Cap phat mang con tro
    for (int i = 0; i < maxSize; i++) {
        q.array[i] = (char *)malloc((MAX_NAME + 1) * sizeof(char)); // Cap phat tung ten khach
    }
    q.front = 0;
    q.rear = -1;  // Ban dau chua co khach
    q.capacity = maxSize;
    return q;
}

// Kiem tra hang doi rong
int isEmpty(Queue q) {
    return q.rear < q.front;
}

// Kiem tra hang doi day
int isFull(Queue q) {
    return q.rear - q.front + 1 >= q.capacity;
}

// Them khach moi vao hang doi
void enqueue(Queue *q, char name[]) {
    if (isFull(*q)) {
        printf("Hang doi day, khong them duoc khach moi.\n");
        return;
    }
    q->rear++;                          // Tang rear de them khach
    strcpy(q->array[q->rear], name);   // Luu ten khach vao vi tri moi
}

// Phuc vu khach dau tien
void serve(Queue *q) {
    if (isEmpty(*q)) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Phuc vu khach: %s\n", q->array[q->front]); // In ten khach dang phuc vu
    q->front++; // Tang front de loai bo khach da phuc vu
}

// Hien thi danh sach khach
void display(Queue q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Danh sach khach dang cho:\n");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d. %s\n", i - q.front + 1, q.array[i]); // In khach kèm so thu tu
    }
}

int main() {
    Queue q = createQueue(MAX_QUEUE); // Tao hang doi 100 khach
    int choice;
    char name[MAX_NAME + 1];

    do {
        // In menu lua chon
        printf("\n----- Menu -----\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach\n");
        printf("3. Hien thi danh sach\n");
        printf("4. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar(); // Doc ky tu '\n' thua

        switch (choice) {
            case 1:
                printf("Nhap ten khach hang: ");
                fgets(name, sizeof(name), stdin);           // Doc ca dong co dau cach
                name[strcspn(name, "\n")] = '\0';           // Xoa ky tu '\n'
                enqueue(&q, name);                          // Them khach
                break;
            case 2:
                serve(&q); // Phuc vu khach
                break;
            case 3:
                display(q); // Hien thi danh sach
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
        free(q.array[i]);
    }
    free(q.array);

    return 0;
}
