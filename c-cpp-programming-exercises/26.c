#include <stdio.h>

int main() {
    int num, i;
    unsigned long long factorial = 1;

    printf("Bir sayi giriniz: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Negatif sayilarin faktoriyeli tanimsizdir.\n");
    } else {
        for (i = 1; i <= num; ++i) {
            factorial *= i;
        }
        printf("%d sayisinin faktoriyeli: %llu\n", num, factorial);
    }

    return 0;
}