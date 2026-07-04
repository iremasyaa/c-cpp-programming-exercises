#include <stdio.h>

int input() {
    int num;
    printf("Bir sayi giriniz: \n");
    scanf("%d", &num);
    return num;
}

int main() {
    int num;
    int i;
    long long factorial = 1;

    num = input();

    if (num < 0) {
        printf("Negatif sayilarin faktoriyeli hesaplanamaz. \n");
    } else {

        for (i = 1; i <= num; i++) {
            factorial *= i;
        }
        printf("%d sayisinin faktoriyeli: %lld\n", num, factorial);
    }
}