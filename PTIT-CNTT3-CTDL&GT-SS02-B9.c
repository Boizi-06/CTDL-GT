//
// Created by admin on 6/17/2025.
//
#include <stdio.h>

int main () {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    int solanXH=1,soXH = arr[0],solan=0;

    for (int i = 0; i < n; ++i) {
        solan=0;
        for (int j = 0; j < n; ++j) {
            if (arr[i] == arr[j]) {
                solan++;
            }
        }
        if (solan > solanXH) {
            solanXH = solan;
            soXH = arr[i];
        }
    }

    printf("so %d xxuat hien %d lan ",soXH,solanXH);


    return 0;
}
