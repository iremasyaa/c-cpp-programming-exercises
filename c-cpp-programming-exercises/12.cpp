#include <stdio.h>

int main() {
    int sayi;

    printf("0 ile 5 arasinda bir sayi girin: ");
    scanf("%d", &sayi);

    if (sayi < 0 || sayi > 5) {
        printf("Lutfen 0 ile 5 arasinda bir sayi girin!\n");
    } else {
        if (sayi % 2 == 0) {
            printf("Girdiginiz sayi %d, bu bir CIFT sayidir.\n", sayi);
        } else {
            printf("Girdiginiz sayi %d, bu bir TEK sayidir.\n", sayi);
        }
    }

    return 0;
}