#include <stdio.h>
#include <stdlib.h>

struct sinhvien {
    int id;
    char name[30];
    int age;
};

int main () {
    int n;
    scanf("%d", &n);
    if (n < 0) return 0;

    struct sinhvien *listsv = (struct sinhvien *) malloc(n * sizeof(struct sinhvien));

    for (int i = 0; i < n; ++i) {
        listsv[i].id = i + 1;
        scanf("%s", listsv[i].name);
        scanf("%d", &listsv[i].age);
    }

    int inputId;
    scanf("%d", &inputId);
    if (inputId <= 0 || inputId > n) {
        printf("khong tim thay");
    } else {
        for (int i = 0; i < n; ++i) {
            if (inputId == listsv[i].id) {
                printf("id : %d \n name : %s \n age : %d \n", listsv[i].id, listsv[i].name, listsv[i].age);
                free(listsv);
                return 0;
            }
        }
    }

    free(listsv);
    return 0;
}
