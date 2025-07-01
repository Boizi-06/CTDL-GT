#include <stdio.h>

// Hàm partition (chia mảng dựa theo pivot)
int partition(int arr[], int low, int high, int pivot_value) {
    // Tìm vị trí pivot trong mảng
    int pivot_pos = -1;
    for (int i = low; i <= high; i++) {
        if (arr[i] == pivot_value) {
            pivot_pos = i;
            break;
        }
    }


    if (pivot_pos == -1) {
        printf("mag thieu so 0");
        return 1;
    }


    // Đổi pivot về cuối
    int temp = arr[pivot_pos];
    arr[pivot_pos] = arr[high];
    arr[high] = temp;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // swap arr[i] và arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Đưa pivot về đúng chỗ
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // trả về vị trí pivot mới
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    int arr[n];
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    partition(arr, 0, n - 1, 0);


    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
