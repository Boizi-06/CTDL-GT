//
// Created by admin on 6/25/2025.
//
#include <stdio.h>

int matrix (int rol,int cow , int i,int j) {
    if (i > rol-1|| j > cow -1) {
        return 0;
    }
    if (i == rol-1 && j ==  cow-1) {
        return 1;
    }

    return matrix(rol,cow,i+1,j) +matrix(rol,cow,i,j+1);

}

int main () {
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    if (n<2||m<2) {
        return 1;
    }
    int rs = matrix(n,m,0,0);
    printf("%d",rs);



    return 0;
}