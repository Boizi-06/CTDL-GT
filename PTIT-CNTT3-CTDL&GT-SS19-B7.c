#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

typedef struct Queue {
    Node* data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue q) {
    return q.front > q.rear;
}

void enqueue(Queue* q, Node* value) {
    if (q->rear == MAX - 1) return;
    q->data[++q->rear] = value;
}

Node* dequeue(Queue* q) {
    if (isEmpty(*q)) return NULL;
    return q->data[q->front++];
}

int searchLevel(Node* root, int target) {
    if (root == NULL) return -1;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int level = 0;
    while (!isEmpty(q)) {
        int count = q.rear - q.front + 1;
        while (count--) {
            Node* curr = dequeue(&q);
            if (curr->data == target) {
                printf("Tìm thấy %d ở tầng %d\n", target, level);
                return level;
            }
            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }
        level++;
    }
    return -1;
}

Node* findNodeinTree(Node* root, int data) {
    if (root == NULL) return NULL;
    if (root->data == data) return root;

    Node* left = findNodeinTree(root->left, data);
    if (left) return left;
    return findNodeinTree(root->right, data);
}

void inputValue(Node** root) {
    int value, choice;

    if (*root == NULL) {
        printf("Mời bạn nhập giá trị node gốc: ");
        scanf("%d", &value);
        *root = createNode(value);
        return;
    }

    printf("Nhập data của node bạn muốn thêm nhánh: ");
    scanf("%d", &value);

    Node* target = findNodeinTree(*root, value);
    if (!target) {
        printf("Node không tồn tại trong cây.\n");
        return;
    }

    printf("Bạn muốn tạo nhánh trái cho node %d? (1=YES, -1=NO): ", value);
    scanf("%d", &choice);
    if (choice == 1 && target->left == NULL) {
        printf("Nhập giá trị cho node trái: ");
        scanf("%d", &value);
        target->left = createNode(value);
    }

    printf("Bạn muốn tạo nhánh phải cho node %d? (1=YES, -1=NO): ", target->data);
    scanf("%d", &choice);
    if (choice == 1 && target->right == NULL) {
        printf("Nhập giá trị cho node phải: ");
        scanf("%d", &value);
        target->right = createNode(value);
    }
}

void displayTree(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        printf("Bạn có muốn thêm node vào cây? (1=YES, -1=NO): ");
        scanf("%d", &choice);
        if (choice == 1) {
            inputValue(&root);
        }
    } while (choice != -1);

    printf("Duyệt cây theo preorder:\n");
    displayTree(root);
    printf("\n");

    int x;
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &x);
    int level = searchLevel(root, x);
    if (level == -1)
        printf("Không tìm thấy %d trong cây.\n", x);

    return 0;
}
