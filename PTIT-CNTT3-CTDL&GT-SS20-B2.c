#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*=========================================
  Cau truc Node cay nhi phan (Binary Tree)
=========================================*/
typedef struct Node {
    int data;              // Du lieu cua Node
    struct Node *left;     // Con trai
    struct Node *right;    // Con phai
} Node;

/*-----------------------------------------
  Tao Node moi tu gia tri x (khong hoi nguoi dung)
-----------------------------------------*/
Node* taoNode(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) {
        printf("Loi: Khong du bo nho!\n");
        exit(1);
    }
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

/*-----------------------------------------
  Tao Node (hoi nguoi dung nhap so nguyen)
  -> tra ve Node* vua tao
-----------------------------------------*/
Node* taoNodeNhap(void) {
    int x;
    printf("Nhap so nguyen cho Node: ");
    if (scanf("%d", &x) != 1) {
        printf("Nhap khong hop le!\n");
        exit(1);
    }
    return taoNode(x);
}

/*-----------------------------------------
  Chen 1 gia tri vao cay theo nguyen tac BST
  (nho hon qua trai, lon hon qua phai, bang thi bo qua hoac xu ly tuy ban)
-----------------------------------------*/
void chenBST(Node **root, int x) {
    if (*root == NULL) {
        *root = taoNode(x);
        return;
    }
    if (x < (*root)->data) {
        chenBST(&((*root)->left), x);
    } else if (x > (*root)->data) {
        chenBST(&((*root)->right), x);
    } else {
        // Neu muon cho phep gia tri trung: co the dem so lan, hoac chen sang 1 ben co dinh.
        // O day minh KHONG chen gia tri trung.
    }
}

/*=========================================
  CAC HAM DUYET CAY
=========================================*/
// 1. NLR - Tien tu (Preorder)
void duyetNLR(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    duyetNLR(root->left);
    duyetNLR(root->right);
}

// 2. LNR - Trung tu (Inorder)
void duyetLNR(Node *root) {
    if (root == NULL) return;
    duyetLNR(root->left);
    printf("%d ", root->data);
    duyetLNR(root->right);
}

// 3. LRN - Hau tu (Postorder)
void duyetLRN(Node *root) {
    if (root == NULL) return;
    duyetLRN(root->left);
    duyetLRN(root->right);
    printf("%d ", root->data);
}

/*-----------------------------------------
  Hang doi don gian dung cho duyet theo tang (Level Order / BFS)
  -> su dung mang dong, tu dong mo rong khi can
-----------------------------------------*/
typedef struct {
    Node **data;    // mang cac con tro Node
    int front;      // chi so lay
    int rear;       // chi so dat tiep
    int capacity;   // suc chua
} Queue;

void qInit(Queue *q, int cap) {
    q->data = (Node**)malloc(sizeof(Node*) * cap);
    if (!q->data) {
        printf("Loi cap phat Queue!\n");
        exit(1);
    }
    q->front = q->rear = 0;
    q->capacity = cap;
}

bool qEmpty(Queue *q) {
    return q->front == q->rear;
}

static void qGrow(Queue *q) {
    int newCap = q->capacity * 2;
    Node **newData = (Node**)malloc(sizeof(Node*) * newCap);
    if (!newData) {
        printf("Loi mo rong Queue!\n");
        exit(1);
    }
    int sz = q->rear - q->front; // so phan tu dang co
    for (int i = 0; i < sz; ++i) {
        newData[i] = q->data[q->front + i];
    }
    free(q->data);
    q->data = newData;
    q->front = 0;
    q->rear = sz;
    q->capacity = newCap;
}

void qPush(Queue *q, Node *node) {
    if (q->rear >= q->capacity) {
        qGrow(q);
    }
    q->data[q->rear++] = node;
}

Node* qPop(Queue *q) {
    if (qEmpty(q)) return NULL;
    return q->data[q->front++];
}

void qFree(Queue *q) {
    free(q->data);
    q->data = NULL;
    q->front = q->rear = q->capacity = 0;
}

// 4. Level Order / BFS
void duyetLevelOrder(Node *root) {
    if (root == NULL) return;
    Queue q; qInit(&q, 16);
    qPush(&q, root);
    while (!qEmpty(&q)) {
        Node *cur = qPop(&q);
        printf("%d ", cur->data);
        if (cur->left) qPush(&q, cur->left);
        if (cur->right) qPush(&q, cur->right);
    }
    qFree(&q);
}

/*-----------------------------------------
  Giai phong cay (de tranh ro ri bo nho)
-----------------------------------------*/
void giaiPhongCay(Node *root) {
    if (root == NULL) return;
    giaiPhongCay(root->left);
    giaiPhongCay(root->right);
    free(root);
}

/*=========================================
  HAM MAIN DEMO
  - Nhap n
  - Nhap n so nguyen
  - Chen vao cay BST
  - In ra 4 kieu duyet
=========================================*/
int main(void) {
    int n;
    printf("Nhap so luong phan tu muon chen vao cay: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So luong khong hop le!\n");
        return 0;
    }

    Node *root = NULL;
    for (int i = 0; i < n; ++i) {
        int x;
        printf("Nhap gia tri thu %d: ", i+1);
        if (scanf("%d", &x) != 1) {
            printf("Nhap khong hop le!\n");
            giaiPhongCay(root);
            return 0;
        }
        chenBST(&root, x);
    }

    printf("\n--- KET QUA DUYET CAY ---\n");
    printf("NLR (Preorder):     "); duyetNLR(root); printf("\n");
    printf("LNR (Inorder):      "); duyetLNR(root); printf("\n");
    printf("LRN (Postorder):    "); duyetLRN(root); printf("\n");
    printf("Level-Order (BFS):  "); duyetLevelOrder(root); printf("\n");

    giaiPhongCay(root);
    return 0;
}
