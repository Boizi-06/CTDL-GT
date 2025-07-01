#include <stdio.h>

void sortCols(int rows, int cols, int matrix[rows][cols], int inputCols) {
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = i + 1; j < rows; j++) {
            if (matrix[i][inputCols] > matrix[j][inputCols]) {
                int temp = matrix[i][inputCols];
                matrix[i][inputCols] = matrix[j][inputCols];
                matrix[j][inputCols] = temp;
            }
        }
    }
}

int main () {
    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);

    if (rows <= 0 || rows > 1000 || cols <= 0 || cols > 1000) {
        printf("So hang hoac cot khong hop le\n");
        return 1;
    }

    int matrix[rows][cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int inputCols;
    while (1) {
        printf("Nhap chi so cot can sap xep (0..%d): ", cols - 1);
        scanf("%d", &inputCols);
        if (inputCols >= 0 && inputCols < cols) {
            break;
        } else {
            printf("Nhap lai!\n");
        }
    }

    sortCols(rows, cols, matrix, inputCols);

    printf("Ma tran sau khi sap xep cot %d:\n", inputCols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
