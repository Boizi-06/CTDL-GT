//
// Created by admin on 7/1/2025.
//
#include <iostream>
using namespace std;

void quickSort (int arr[],int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[right];
    int i = left -1;
    for (int j =0 ; j < right ; j ++) {
        if (arr[j] > pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }
    int temp = arr[i+1];
    arr[i+1] = arr[right-1];
    arr[right-1] = temp;
    int indexPivot = i +1;
    quickSort(arr, left, indexPivot - 1);
    quickSort(arr, indexPivot + 1, right);

}
void printArr (int arr[],int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << endl;
}

int main () {
    long int n;
    std::cin >> n;
    if (n < 0 || n > 1000) {
        std::cout << "vuot gioi han n";
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    printArr(arr,n);
    quickSort(arr,0,n-1);
    printArr(arr,n);
    cout << "\nPhan tich do phuc tap:" << endl;
    cout << "Quick Sort: Trung binh O(n log n), xau nhat O(n^2)" << endl;


}