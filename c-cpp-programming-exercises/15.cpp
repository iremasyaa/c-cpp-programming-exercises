#include <stdio.h>

int main() {
    int sayilar[5];

    printf("Lutfen 5 sayi girin:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d. sayiyi girin: ", i + 1);
        scanf("%d", &sayilar[i]);
    }

    printf("\nGirilen sayilarin siniflandirilmasi:\n");

    for (int i = 0; i < 5; i++) {
        if (sayilar[i] > 0) {
            printf("%d. sayi (%d) POZITIF\n", i + 1, sayilar[i]);
        } else if (sayilar[i] < 0) {
            printf("%d. sayi (%d) NEGATIF\n", i + 1, sayilar[i]);
        } else {
            printf("%d. sayi (%d) NE POZITIF NE DE NEGATIF (Sifir)\n", i + 1, sayilar[i]);
        }
    }

    return 0;
}
