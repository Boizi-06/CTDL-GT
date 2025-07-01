//
// Created by admin on 7/1/2025.
//
#include <iostream>
using namespace std;

// Hàm sắp xếp chèn
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Lưu phần tử đang xét
        int j = i - 1;

        // Dịch các phần tử lớn hơn key sang phải
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Chèn key vào đúng vị trí
        arr[j + 1] = key;
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    if (n <= 0 || n >= 1000) {
        cout << "So luong phan tu khong hop le" << endl;
        return 1;
    }

    int arr[n];
    cout << "Nhap cac phan tu: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Mang truoc khi sap xep: ";
    printArray(arr, n);

    // Gọi hàm sắp xếp chèn
    insertionSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    // Phân tích độ phức tạp
    cout << "\nPhan tich do phuc tap:" << endl;
    cout << "Thoi gian chay (Worst case): O(n^2)" << endl;
    cout << "Thoi gian chay (Best case): O(n)" << endl;
    cout << "Thoi gian chay (Average case): O(n^2)" << endl;

    return 0;
}
