#include <stdio.h>

int sum(int arr[], int n, int rs) {
    if (n <= 0) {
        return rs;
    }
    rs += arr[n - 1];
    return sum(arr, n - 1, rs);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Tong mang = %d\n", sum(arr, n, 0));
    return 0;
}
