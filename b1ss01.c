#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    int n ;
    scanf("%d",&n);
    int a[n],sum;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    sum = 0;
    for(int i=0;i<n;i++) {
       sum+=a[i];
    }

    printf("%d",sum);

    return 0;
}