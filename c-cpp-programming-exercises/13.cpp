#include <stdio.h>

int main() {
    int sayi, toplam = 0;

    printf("Lutfen 5 sayi giriniz:\n");

    for (int i = 1; i <= 5; i++) {
        printf("%d. sayiyi giriniz: ", i);
        scanf("%d", &sayi);
        toplam += sayi;  
    }

    printf("Girilen 5 sayinin toplami: %d\n", toplam);

    return 0;
}