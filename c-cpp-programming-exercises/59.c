#include <stdio.h>


void getMatrix(int matrix[2][2]);
void printMatrix(int matrix[2][2]);
void addMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]);
void multiplyMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]);

int main() {
    int matrix1[2][2], matrix2[2][2], result[2][2];
    int operation;
    char devam = 'e';

    while (devam == 'e' || devam == 'E') {
        printf("\n=== 2x2 Matris Islemleri ===\n");
        printf("[1] - Toplama\n");
        printf("[2] - Carpma\n");
        printf("[0] - Cikis\n");

        do {
            printf("\nHangi islemi yapmak istiyorsaniz basindaki sayiyi giriniz > ");
            scanf("%d", &operation);
        } while (operation < 0 || operation > 2);

        if (operation == 0) {
            printf("Programdan cikiliyor...\n");
            break;
        }

        printf("\n1. Matris degerlerini giriniz:\n");
        getMatrix(matrix1);

        printf("\n2. Matris degerlerini giriniz:\n");
        getMatrix(matrix2);

        if (operation == 1) { // Toplama işlemi
            addMatrices(matrix1, matrix2, result);
            printf("\nMatrislerin toplami:\n");
        } else if (operation == 2) { // Çarpma işlemi
            multiplyMatrices(matrix1, matrix2, result);
            printf("\nMatrislerin carpimi:\n");
        }

        printMatrix(result);

        getchar(); // Buffer temizleme
        printf("\nYeni islem yapmak istiyor musunuz? (e/h) > ");
        devam = getchar();
    }

    return 0;
}

// Kullanıcıdan matris girişini alır
void getMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("[%d][%d] elemani: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Matrisi ekrana yazdırır
void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        printf("\n");
        for (int j = 0; j < 2; j++) {
            printf(" %2d", matrix[i][j]);
        }
    }
    printf("\n");
}

// Matrisleri toplar
void addMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Matrisleri çarpar
void multiplyMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
