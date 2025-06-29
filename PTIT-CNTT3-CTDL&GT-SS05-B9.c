//
// Created by admin on 6/25/2025.
//
#include <stdio.h>

int matrix (int rol,int cow ) {
    if (rol < 0|| cow < 0) {
        return 0;
    }
    if (rol==0 && cow==0) {
        return 1;
    }

    return matrix(rol-1,cow) +matrix(rol,cow-1);

}

int main () {
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    if (n<1&&m<1) {
        return 1;
    }
    int rs = matrix(n,m);
    printf("%d",rs);



    return 0;
}