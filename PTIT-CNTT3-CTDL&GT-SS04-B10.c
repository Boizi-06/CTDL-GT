//
// Created by admin on 6/20/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct sinhvien {
    int id;
    char name[50];
    int age;
};

int main () {
    int n;
    printf("nhap so luong cua mang thong tin sinh vien : ");
    scanf("%d", &n);
    if (n < 0) return 0;

    struct sinhvien *listsv = (struct sinhvien*) calloc(n, sizeof(struct sinhvien));

    for (int i = 0; i < n; ++i) {
        listsv[i].id = i + 1;
        printf("nhap ten sinh vien: ");
        scanf("%s", listsv[i].name);
        printf("nhap tuoi sinh vien: ");
        scanf("%d", &listsv[i].age);
    }

    char inputname[50];
    printf("Nhap ten can tim: ");
    scanf("%s", inputname);


    for (int i = 0; inputname[i] != '\0'; ++i) {
        inputname[i] = tolower(inputname[i]);
    }


    for (int i = 0; i < n; ++i) {
        char copyName[50];
        strcpy(copyName, listsv[i].name);
        for (int j = 0; copyName[j] != '\0'; ++j) {
            copyName[j] = tolower(copyName[j]);
        }

        if (strstr(copyName, inputname) != NULL) {
            printf("{ id: %d, name: \"%s\", age: %d }\n", listsv[i].id, listsv[i].name, listsv[i].age);
        }
    }

    free(listsv);
    return 0;
}
