//
// Created by admin on 7/6/2025.
//
//
// Created by admin on 7/6/2025.
//
//
// Created by admin on 7/6/2025.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printFromHead(node* head) {
    node* current = head;
    printf("\nNULL->");
    while (current != NULL) {
        printf("%d<->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int getLength(node* head) {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void insertAtHead(node** head, node** tail, int value) {
    node* newNode = createNode(value);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtPosition(node** head, node** tail, int value, int position) {
    int length = getLength(*head);

    if (position <= 1) {
        insertAtHead(head, tail, value);
        return;
    } else if (position > length) {
        node* newNode = createNode(value);
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
        return;
    }

    node* newNode = createNode(value);
    node* current = *head;

    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}
void deleteHead(node** head, node** tail) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }

    node* temp = *head;

    if (*head == *tail) {
        *head = *tail = NULL;
    } else {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }

    free(temp);
}
void deleteTail(node** head, node** tail) {
    if (*tail == NULL) {
        printf("Danh sach rong!\n");
        return;
    }

    node* temp = *tail;

    if (*head == *tail) {
        *head = *tail = NULL;
    } else {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }

    free(temp);
}
void deleteAtPosition(node** head, node** tail, int position) {
    int length = getLength(*head);

    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }

    if (position <= 1) {
        deleteHead(head, tail);
        return;
    } else if (position >= length) {
        deleteTail(head, tail);
        return;
    }

    node* current = *head;


    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Vi tri khong hop le!\n");
        return;
    }


    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}
void reverseList(node** head, node** tail) {
    node* current = *head;
    node* temp = NULL;

    while (current != NULL) {

        temp = current->prev;
        current->prev = current->next;
        current->next = temp;


        current = current->prev;
    }



    if (temp != NULL) {
        *head = temp->prev;
    }
}
void swapAdjacentPairs(node** head, node** tail) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    node* current = *head;

    while (current != NULL && current->next != NULL) {
        node* first = current;
        node* second = current->next;

        // Giữ node trước first và node sau second
        node* prevNode = first->prev;
        node* nextNode = second->next;

        // Hoán đổi
        if (prevNode != NULL) {
            prevNode->next = second;
        } else {
            *head = second; // Nếu first là head, thì head mới là second
        }

        if (nextNode != NULL) {
            nextNode->prev = first;
        } else {
            *tail = first; // Nếu second là tail, tail mới là first
        }

        second->prev = prevNode;
        second->next = first;

        first->prev = second;
        first->next = nextNode;

        // Di chuyển sang cặp tiếp theo
        current = first->next;
    }
}

int main() {
    int n, value;
    node *head = NULL, *tail = NULL;

    printf("Nhap so luong node: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Nhap gia tri node thu %d: ", i);
        scanf("%d", &value);

        node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    printFromHead(head);



    swapAdjacentPairs(&head, &tail);


    printFromHead(head);





    return 0;
}
