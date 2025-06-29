//
// Created by admin on 6/26/2025.
// bai toan thap ha noi
#include <stdio.h>
void thaphanoi (int n,char a, char b,char c) {
    if (n==1) {
        printf("Di chuyen dia 1 tu cot %c sang cot %c\n", a, c);
        return;
    }
    thaphanoi(n-1,a,c,b);
    printf("di chuyen dia %d tu cot %c sang cot %c \n",n,a,c);
    thaphanoi(n-1,b,a,c);
}
int main () {
    thaphanoi(2, 'A', 'B', 'C');
    return 0;
}