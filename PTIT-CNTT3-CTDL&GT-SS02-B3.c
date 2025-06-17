#include <stdio.h>
int main () {
    int n;
    scanf("%d", &n);

    if (n < 0 || n > 100) return 0;

    int arr1[n], arr2[n];


    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr1[i]);
    }


    for (int i = 0; i < n; ++i) {
        arr2[i] = arr1[n - 1 - i];
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr2[i]);
    }

    return 0;
}
