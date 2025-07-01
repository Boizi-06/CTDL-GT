//
// Created by admin on 7/1/2025.
//
#include <iostream>
using namespace std;

// Hàm sắp xếp chèn (Insertion Sort)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Dịch các phần tử lớn hơn key sang phải
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm tìm kiếm tuyến tính
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  // Trả về vị trí đầu tiên tìm thấy
        }
    }
    return -1;  // Không tìm thấy
}

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;  // Tìm thấy
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Không tìm thấy
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

    cout << "Mang ban dau: ";
    printArray(arr, n);

    // Sắp xếp mảng bằng insertion sort
    insertionSort(arr, n);

    cout << "Mang sau khi sap xep (Insertion Sort): ";
    printArray(arr, n);

    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    // Tìm kiếm tuyến tính
    int posLinear = linearSearch(arr, n, x);
    if (posLinear != -1)
        cout << "Tim kiem tuyen tinh: Tim thay tai vi tri " << posLinear + 1 << endl;
    else
        cout << "Tim kiem tuyen tinh: Khong tim thay" << endl;

    // Tìm kiếm nhị phân
    int posBinary = binarySearch(arr, n, x);
    if (posBinary != -1)
        cout << "Tim kiem nhi phan: Tim thay tai vi tri " << posBinary + 1 << endl;
    else
        cout << "Tim kiem nhi phan: Khong tim thay" << endl;

    // Phân tích độ phức tạp
    cout << "\nPhan tich do phuc tap:" << endl;
    cout << "Insertion Sort: O(n^2)" << endl;
    cout << "Linear Search: O(n)" << endl;
    cout << "Binary Search: O(log n)" << endl;

    return 0;
}
