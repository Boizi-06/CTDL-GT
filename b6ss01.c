#include <stdio.h>

int main() {
    printf("Hello, World!\n");

    int n;
    printf("nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu cua mang: ");
        scanf("%d", &arr[i]);
    }
    int a ;
    printf("nhap vi tri cua phan tu ma ban muon dem so lan so xuat hien trong mang");
    scanf("%d", &a);
    if (a<0|| a>n) {
        printf("vi tri khong ton tai \n");

    } else {
        int c;
        for (int i = 0; i < n; i++) {
            if (arr[i]==arr[a]) {
                c+=1;
            }
        }
        printf("phan tu %d xuat hien %d lan trong mang  ",a,c);
    }



    return 0;
}
