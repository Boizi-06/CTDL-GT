#include <iostream>
#include <algorithm>
using namespace std;

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; // trả về chỉ số nếu tìm thấy
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
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
    cout << "Nhap cac phan tu bat ky:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sắp xếp mảng tăng dần
    sort(arr, arr + n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    // Gọi hàm tìm kiếm nhị phân
    int pos = binarySearch(arr, n, x);

    if (pos != -1) {
        cout << "Phan tu o vi tri thu " << pos + 1 << endl;
    } else {
        cout << "Khong ton tai phan tu" << endl;
    }

    // Phân tích độ phức tạp
    cout << "\nPhan tich do phuc tap:\n";
    cout << "Thoi gian chay sort: O(n log n)\n";
    cout << "Thoi gian chay binary search: O(log n)\n";

    return 0;
}
