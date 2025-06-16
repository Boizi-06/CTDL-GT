#include <stdio.h>

int main () {
    int n,m;
    printf("moi ban nhap so dong");
    scanf("%d",&n);
    printf("moi ban nhap so cot");
    scanf("%d",&m);
    int arr[n][m];

    for (int i = 0 ; i < n ; i++ ) {
        for (int j = 0 ; j < n ; j++ ) {
            printf("nhap phan tu arr[%d][%d]",i,j);
            scanf("%d",&arr[i][j]);
        }
    }


    for (int i = 0 ; i < n ; i++ ) {

        for (int j = 0 ; j < n ; j++ ) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    // hàm in toàn bộ phần tử có độ phức tạp về thời gian là O(n) bình ,độ phức tạp về không gian là O(1)


    for (int i = 0 ; i < n ; i++ ) {

        for (int j = 0 ; j < n ; j++ ) {
            if (i==j) {
                printf("%d",arr[i][j]);
            } else {
                printf("  ");
            }



        }
        printf("\n");
    }
    // hàm in duong cheo chinh co do phuc tap thoi gian la O(n) binh phuong
    return 0;
}
