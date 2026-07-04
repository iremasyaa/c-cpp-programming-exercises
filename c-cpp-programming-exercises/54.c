#include <stdio.h>
#include <stdlib.h>

int** matrix[3];

int** allocateMatrix(int, int);
void printMatrix(int**);
void getMatrixElement(int**);
void getMatrixSize(int);
void calSizesOfResultMatrix(int);
void add();
void multiple();
void freeAll();

int main(){
    int operation;
    char devam='e';
    
    while( devam == 'e' || devam == 'E' ){
        freeAll();
        printf("\n=== Matrix islemleri ===\n");
        printf("[1] - Toplama\n");
        printf("[2] - Carpma(iki matris icin)\n");
        printf("[0] - Cikis\n");
        
        do{
            printf("\nHangi islemi yapmak istiyorsaniz basindaki sayiyi giriniz > ");
            scanf("%d", &operation);
        }while( operation < 0 || operation > 2 );
        
        switch( operation ){
            case 1:
                getMatrixSize(2);
                if( matrix[0] == NULL || matrix[1] == NULL || matrix[0][0][0] != matrix[1][0][0] || matrix[0][0][1] != matrix[1][0][1] ){
                    printf("HATA : Toplama icin iki matrisin satir ve sutun sayilari esit olmali!\n");
                    continue;
                }
                add();
                printf("Matrislerin toplami:\n");
                break;
            case 2: // Carpma
                getMatrixSize(2);
                if( matrix[0] == NULL || matrix[1] == NULL || matrix[0][0][1] != matrix[1][0][0] ){
                    printf("HATA : Carpma islemi icin 1.matrisin sutun sayisi 2.matrisin satir sayisina esit olmali!\n");
                    continue;
                }
                multiple();
                printf("Matrislerin carpimi:\n");
                break;
            case 0:
                return 0;
        }
        printMatrix(matrix[2]);
        
        getchar();
        printf("\nYeni islem e/h? > ");
        devam = getchar();
    }
    return 0;
}

int** allocateMatrix(int row, int col){
    int i;
    int **matrixPointer;
    row++;
    col++;
    matrixPointer = (int**)malloc(row * sizeof(int*));
    if (matrixPointer == NULL) {
        printf("HATA: Bellek tahsisi basarisiz!\n");
        exit(1);
    }
    for( i=0; i<row; i++ ){
        matrixPointer[i] = (int*)malloc(col * sizeof(int));
        if (matrixPointer[i] == NULL) {
            printf("HATA: Bellek tahsisi basarisiz!\n");
            exit(1);
        }
    }
    matrixPointer[0][0] = row;
    matrixPointer[0][1] = col;
    return matrixPointer;
}

void printMatrix(int** theMatrix){
    if (theMatrix == NULL) return;
    int i,j;
    for( i=1; i<theMatrix[0][0]; i++ ){
        printf("\n");
        for( j=1; j<theMatrix[0][1]; j++ ){
            printf(" %2d", theMatrix[i][j]);
        }
    }
    printf("\n\n");
}

void getMatrixElement(int** theMatrix){
    int i,j;
    for( i=1; i<theMatrix[0][0]; i++ ){
        for( j=1; j<theMatrix[0][1]; j++ ){
            printf("[%d][%d] elemani: ", i,j);
            scanf("%d", &theMatrix[i][j]);
        }
    }
}

void getMatrixSize(int numberOfMatrix){
    int i, row, col;
    for( i=0; i<numberOfMatrix; i++ ){
        printf("\n%d.Matrisin Satir Sayisi > ", i+1);
        scanf("%d", &row);
        printf("\n%d.Matrisin Sutun Sayisi > ", i+1);
        scanf("%d", &col);
        matrix[i] = allocateMatrix(row, col);
        getMatrixElement(matrix[i]);
    }
}

void calSizesOfResultMatrix(int op){
    int row, col;
    if( op == 1 ){
        row = matrix[0][0][0] - 1;
        col = matrix[0][0][1] - 1;
    } else {
        row = matrix[0][0][0] - 1;
        col = matrix[1][0][1] - 1;
    }
    matrix[2] = allocateMatrix(row, col);
}

void add(){
    int i,j;
    calSizesOfResultMatrix(1);
    for( i=1; i<matrix[0][0][0]; i++ ){
        for( j=1; j<matrix[0][0][1]; j++ ){
            matrix[2][i][j] = matrix[0][i][j] + matrix[1][i][j];
        }
    }
}

void multiple(){
    int i,j,k;
    calSizesOfResultMatrix(2);
    for( i=1; i<matrix[0][0][0]; i++ ){
        for( j=1; j<matrix[1][0][1]; j++ ){
            matrix[2][i][j] = 0;
            for( k=1; k<matrix[0][0][1]; k++ ){
                matrix[2][i][j] += matrix[0][i][k] * matrix[1][k][j];
            }
        }
    }
}

void freeAll(){
    int i, j;
    for(i=0; i<3; i++){
        if(matrix[i] != NULL){
            for(j=0; j<matrix[i][0][0]; j++){
                free(matrix[i][j]);
            }
            free(matrix[i]);
            matrix[i] = NULL;
        }
    }
}