//
// Created by admin on 7/1/2025.
//
#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Mỗi lần duyệt "nổi" phần tử lớn nhất lên cuối dãy
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi arr[j] và arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    // Gọi hàm sắp xếp tự viết
    bubbleSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    // Phân tích độ phức tạp
    cout << "\nPhan tich do phuc tap:" << endl;
    cout << "Thoi gian chay (Worst case): O(n^2)" << endl;
    cout << "Thoi gian chay (Best case): O(n)" << endl;
    cout << "Thoi gian chay (Average case): O(n^2)" << endl;

    return 0;
}

