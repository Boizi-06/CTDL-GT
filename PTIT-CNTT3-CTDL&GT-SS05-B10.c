//
// Created by admin on 6/25/2025.
//
#include <stdio.h>

int findMazepath (int n,int m,int i ,int j,int blocki,int blockj) {

    if (i > n -1 || j > m -1) {
        return 0;
    }
    if (i == blocki && j == blockj) {
        return 0;
    }
    if (i == n-1 && j == m-1) {
        return 1;
    }

    return findMazepath(n,m,i+1,j,blocki,blockj) + findMazepath(n,m,i,j+1,blocki,blockj);
}





int main () {
    int n,m,blockN,blockM;
    printf("moi ban nhap so hang cua ma tran");
    scanf("%d",&n);
    printf("moi ban nhap so cot cua ma tran");
    scanf("%d",&m);
    printf("moi ban nhap index cua hang bi blcok");
    scanf("%d",&blockN);
    printf("moi ban nhap index cua cot bi blcok");
    scanf("%d",&blockM);

    if (n < 2 || m < 2) {
        printf("nam ngoai pham vi!\n");
        return 1;
    } else if (blockN >= n || blockM >= m) {
        printf("o bi block nam ngoai pham i ma tran!\n");
        return 1;
    } else if (blockN == n - 1 && blockM == m - 1) {
        printf("ko duoc block o dich\n");
        return 1;
    }
    int result = findMazepath(n,m,0,0,blockN,blockM);
    printf("so duong di hop le %d",result);




    return 0;
}



