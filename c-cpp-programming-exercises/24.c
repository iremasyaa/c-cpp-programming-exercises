#include <stdio.h>

float input(ort) {
    float x;
    printf("%s", ort);
    scanf("%f", &x);
    return x;
}


int main() {
    float sayi1, sayi2, ortalama;

    sayi1 = input("Birinci sayiyi girin: ");
    sayi2 = input("Ikinci sayiyi girin: ");

    ortalama = (sayi1 + sayi2) / 2;

    printf("Girilen sayilarin ortalamasi: %.2f\n", ortalama);

    return 0;
}


