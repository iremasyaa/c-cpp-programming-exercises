#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW1 2 
#define COL1 3 
#define ROW2 3 
#define COL2 2 

void randomValueGenerator(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void multiplyMatrices(int A[ROW1][COL1], int B[ROW2][COL2], int result[ROW1][COL2]);
void summatrix(int array1[ROW1][COL1], int array2[ROW2][COL2]);

int main() {
    srand(time(NULL));

    int array1[ROW1][COL1];
    int array2[ROW2][COL2];
    int targetMatrix[ROW1][COL2];

    randomValueGenerator(ROW1, COL1, array1);
    randomValueGenerator(ROW2, COL2, array2);

    printf("*****-Dizi1 (A - 2x3)-*****\n");
    printMatrix(ROW1, COL1, array1);
    
    printf("*****-Dizi2 (B - 3x2)-*****\n");
    printMatrix(ROW2, COL2, array2);

    printf("***Toplama***\n");
    summatrix(array1,array2);

    printf("\n*****-Matris-Carpimi (A x B = 2x2)-*****\n");
    multiplyMatrices(array1, array2, targetMatrix);
    printMatrix(ROW1, COL2, targetMatrix);

    return 0;
}

void randomValueGenerator(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int A[ROW1][COL1], int B[ROW2][COL2], int result[ROW1][COL2]) {
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COL1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void summatrix(int array1[ROW1][COL1], int array2[ROW2][COL2]) {
    int result[ROW1][COL1];  

    if (ROW1 != ROW2 || COL1 != COL2) {  
        printf("Toplama islemi yapilamaz, matris boyutlari uyusmuyor.\n");
        return;
    }

    printf("\n*****-Matris Toplami (A + B)-*****\n");
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL1; j++) {  
            result[i][j] = array1[i][j] + array2[i][j];
            printf("%3d ", result[i][j]);  
        }
        printf("\n");
    }
}