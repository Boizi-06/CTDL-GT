//
// Created by admin on 6/25/2025.
// kiểm tra chuối đối xứng bằng đệ quy;
#include <stdio.h>
#include <string.h>

int symmetricchain (char string[] , int n,int i,int count) {

    if (count == n/2) {
        return 1;
    }
    if (i > n/2 ) {
        return -1;
    }

    if (string[i] == string[n-1-i]) {
        count++;
    }
    return symmetricchain(string,n,i+1,count);

}

int main () {
    char string[] = "abcd12dcba";
    int n = strlen(string);
    if (symmetricchain(string,n,0,0)==1) {
        printf("chuoi doi xung");
    } else {
        printf("chuoi ko doi xung11");
    }


    return 0;
}
