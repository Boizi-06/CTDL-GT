//
// Created by admin on 7/1/2025.
//
#include <iostream>
using namespace std;

// Hàm tìm kiếm tuyến tính
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // trả về chỉ số đầu tiên tìm thấy
        }
    }
    return -1; // không tìm thấy
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    if (n <= 0 || n >= 1000) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 1;
    }

    int arr[n];
    cout << "Nhap cac phan tu:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    // Gọi hàm tìm kiếm
    int pos = linearSearch(arr, n, x);

    if (pos != -1) {
        cout << "Vi tri thu " << pos  << endl;
    } else {
        cout << "Khong ton tai phan tu" << endl;
    }

    // Phân tích độ phức tạp
    cout << "\nPhan tich do phuc tap:" << endl;
    cout << "Thoi gian chay (Worst case): O(n)" << endl;
    cout << "Thoi gian chay (Best case): O(1)" << endl;
    cout << "Thoi gian chay (Average case): O(n)" << endl;

    return 0;
}
