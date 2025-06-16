#include <stdio.h>

int main (){
    int arr[]= {10,20,30,40};
    int length = sizeof(arr)/sizeof(arr[0]);
    int a = arr[0];
    for(int i=1;i<length;i++) {
        if (a== arr[i]) {
            printf("co so lap lai \n");
            return 0;
        }
    }
    printf("ko co so lap lai \n");

    int arr2[]= {10,20,30,40,10};
    int length2 = sizeof(arr2)/sizeof(arr2[0]);
    for (int i = 0 ; i< length2 -1 ; i++) {
        for (int j = 1; j < length2 ; j++) {
            if (arr2[i]==arr2[j]) {
                printf("co so lap lai \n");
                return 0;
            }

        }
    }
    printf("ko co so lap lai \n");

    // cach 1 co do phức tạp thuat toan la o(n) cach 2 la o (n) binh

    return 0;
}
