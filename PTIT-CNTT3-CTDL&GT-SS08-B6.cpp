#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l[n1], r[n2];


    for (int i = 0; i < n1; ++i) {
        l[i] = arr[left + i];
    }

    for (int i = 0; i < n2; ++i) {
        r[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    if (n <= 0 || n >= 1000) {
        cout << "So luong phan tu khong hop le" << endl;
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }


    printArr(arr, n);

    mergeSort(arr, 0, n - 1);


    printArr(arr, n);

    cout << "\nPhan tich do phuc tap:\n";
    cout << "Merge Sort: O(n log n) trong moi truong hop" << endl;

    return 0;
}
