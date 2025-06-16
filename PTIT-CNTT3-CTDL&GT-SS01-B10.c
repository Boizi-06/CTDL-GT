#include <stdio.h>
#include <string.h>

struct CharCount {
    char letter;
    int count;
};

int main() {
    char str1[100];
    char str2[100];
    struct CharCount letters[26];
    struct CharCount letters2[26];

    // Khởi tạo: gán từng chữ cái từ 'a' đến 'z'
    for (int i = 0; i < 26; i++) {
        letters[i].letter = 'a' + i;
        letters[i].count = 0;
        letters2[i].letter = 'a' + i;
        letters2[i].count = 0;
    }




    // Nhập chuỗi
    printf("Nhap chuoi 1(chi dung chu a-z hoac A-Z): ");
    scanf("%s", str1);
    printf("Nhap chuoi 2(chi dung chu a-z hoac A-Z): ");
    scanf("%s", str2);


    int length1 = strlen(str1);
    int length2 = strlen(str2);
    if (length1 != length2 || length1 == 0) {
        printf("false");
        return 0;
    }


    for (int i = 0; str1[i] != '\0'; i++) {
        char c1 = str1[i];
        char c2 = str2[i];





        for (int j = 0; j < 26; j++) {
            if (c1 == letters[j].letter) {
                letters[j].count++;
                break;
            }
        }


        for (int k = 0; k < 26; k++) {
            if (c2 == letters2[k].letter) {
                letters2[k].count++;
                break;
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < 26; i++) {
        if (letters[i].count != letters2[i].count) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("true");
    } else {
        printf("fales");
    }

    // do phuc tap ve thoi gian cua thuat toan la 0(n) binh phuong
    return 0;
}
