//
// Created by admin on 7/2/2025.
//
//
// Created by admin on 7/2/2025.
//
//
// Created by admin on 7/2/2025.
//
//
// Created by admin on 7/2/2025.
//

//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next ;
}node;


node* createNode (int data) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode ->data = data;
    newnode ->next = NULL;
    return newnode;
}
void insertHead (node** head,int data) {
    node* newnode = createNode(data);
    newnode->next = *head;
    *head = newnode;
}

void printNode (node* head) {
    node* curent = head;
    while (curent!= NULL) {
        printf("%d->",curent->data);
        curent=curent->next;
    }
    printf("NULL");
}

void findNode (node* head,int value) {
    node* curent = head;
    while (curent != NULL) {
        if (curent->data == value) {
            printf("true");
            return ;
        }
        curent=curent->next;

    }
    printf("fales");
    return ;

}
int lengthNode (node* head , int lenght) {
    node* curent = head;
    while (curent!= NULL) {
        lenght++;
        curent=curent->next;
    }
    return lenght;
}
void deleteHead(node** head) {
    if (*head == NULL) {
        return;
    }
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}


void insertNodepos (node** head,int data,int pos) {
    node* newnode = createNode(data);
    if (pos==0) {
        insertHead(&head , data);
        free(newnode);
        return;
    }
    node* curent = *head;
    int i=0;
    while (i < pos-1 && curent!=NULL) {
        curent = curent->next;
        i++;
    }
    if (curent==NULL) {
        free(newnode);
        return;
    }
    newnode->next = curent ->next;
    curent->next = newnode;
}
void deleteNodePos(node** head, int pos) {
    if (*head == NULL) return;

    if (pos == 0) {
        deleteHead(head);
        return;
    }

    node* curent = *head;
    int i = 0;
    while (i < pos - 1 && curent != NULL) {
        curent = curent->next;
        i++;
    }

    if (curent == NULL || curent->next == NULL) {
        printf("Vi tri khong hop le\n");
        return;
    }

    node* temp = curent->next;
    curent->next = temp->next;
    free(temp);
}
void reverseLisdNode(node** head) {
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}
void swapNode(node* head) {
    node* current = head;
    while (current != NULL && current->next != NULL) {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        current = current->next->next;
    }
}

int main () {
    int n;
    printf("nhap so luong node muon tao");
    scanf("%d",&n);
    int arr[n];
    printf("nhap gia tri cua cac node \n");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    node* head = createNode(arr[0]);
    node* curent = head;
    for (int i = 1; i < n; ++i) {
        node* newnode = createNode(arr[i]);
        curent->next = newnode;
        curent = newnode;
    }


    printNode(head);
    printf("\n");
    reverseLisdNode(&head);
    printf("\n");
    printNode(head);
    printf("\n");
    swapNode(head);
    printNode(head);




    return 0;
}