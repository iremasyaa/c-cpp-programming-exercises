 #include <stdio.h>

int main() {
    int sayi1, sayi2;
    float sonuc; 
    char islemSec;


    while (1) {
        printf("Birinci Sayiyi Giriniz: ");
        if (scanf("%d", &sayi1) == 1) break;
        printf("Hata: Sayisal bir deger giriniz.\n");
        while (getchar() != '\n');
    }
  

    while (1) {
        printf("Ikinci Sayiyi Giriniz: ");
        if (scanf("%d", &sayi2) == 1) break;
        printf("Hata: Sayisal bir deger giriniz.\n");
        while (getchar() != '\n'); 
    }

    
    while (1) {
        printf("Bir islem seciniz ('+', '-', '*', '/'): ");
        scanf(" %c", &islemSec);

        if (islemSec == '+' || islemSec == '-' || islemSec == '*' || islemSec == '/') {
            break;
        }
        printf("Hata: Gecersiz bir islem secildi. Lutfen tekrar deneyiniz.\n");
    }

     
    if (islemSec == '/') {
        while (sayi2 == 0) {
            printf("Hata: Sayinin 0'a bolumu tanimsizdir. Lutfen ikinci sayiyi tekrar giriniz: ");
            scanf("%d", &sayi2);
        }
    }
    
    switch (islemSec) {
        case '+':
            sonuc = sayi1 + sayi2;
            printf("%d + %d = %.2f\n", sayi1, sayi2, sonuc);
            break;
        case '-':
            sonuc = sayi1 - sayi2;
            printf("%d - %d = %.2f\n", sayi1, sayi2, sonuc);
            break;
        case '*':
            sonuc = sayi1 * sayi2;
            printf("%d * %d = %.2f\n", sayi1, sayi2, sonuc);
            break;
        case '/':
            sonuc = (float)sayi1 / sayi2;
            printf("%d / %d = %.2f\n", sayi1, sayi2, sonuc);
            break;
        default:
            printf("Lutfen gecerli bir islem giriniz");
            break;
    }
    return 0;
}