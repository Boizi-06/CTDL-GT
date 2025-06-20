//
// Created by admin on 6/19/2025.
//

#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    scanf("%d",&n);
    if (n<0) {
        printf('enor');
        return 0;
    }

    int *arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf('enor');
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    for (int i = 0; i < n; ++i) {
        if ( max < arr[i] ) {
            max = arr[i];
        }


    }
    printf("%d",max);
    free(arr);
    return 0;
}

