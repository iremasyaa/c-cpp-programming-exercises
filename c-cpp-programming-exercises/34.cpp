#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonksiyon prototipleri
int input();
int zarAt(int zarSayisi);
void sonucYazdir(int oyuncu1Skor, int oyuncu2Skor);

int main() {
    srand(time(NULL)); // Rastgele sayı üretimi için seed oluşturuluyor.

    // Kullanıcıdan zar sayısını al
    int zarSayisi = input();

    // Oyuncu 1'in zar atışları
    printf("\nOyuncu 1 zar atıyor: \n");
    int oyuncu1Skor = zarAt(zarSayisi);
    printf("Oyuncu 1 toplam skoru: %d\n\n", oyuncu1Skor);

    // Oyuncu 2'nin zar atışları
    printf("Oyuncu 2 zar atıyor: \n");
    int oyuncu2Skor = zarAt(zarSayisi);
    printf("Oyuncu 2 toplam skoru: %d\n\n", oyuncu2Skor);

    // Sonuçları yazdır
    sonucYazdir(oyuncu1Skor, oyuncu2Skor);

    return 0;
}

// Kullanıcıdan giriş al
int input() {
    int x;
    while (1) { // Doğru bir giriş yapılana kadar döngü
        printf("Kac zar atilacak? (Sadece 2 zar atabilirsiniz): ");
        scanf("%d", &x);

        if (x == 2) {
            return x; // Doğru giriş yapıldı, döngüden çık
        } else {
            printf("Yanlis sayi girdiniz! Lutfen sadece 2 girin.\n");
        }
    }
}

// Zar atma fonksiyonu
int zarAt(int zarSayisi) {
    int toplamSkor = 0;
    for (int i = 1; i <= zarSayisi; i++) {
        int zar = (rand() % 6) + 1; // 1 ile 6 arasında zar at
        toplamSkor += zar;
        printf("Zar %d: %d\n", i, zar);
    }
    return toplamSkor;
}

// Sonuçları yazdırma fonksiyonu
void sonucYazdir(int oyuncu1Skor, int oyuncu2Skor) {
    printf("=== Sonuc ===\n");

    if (oyuncu1Skor > oyuncu2Skor) {
        printf("En sansli oyuncu: Oyuncu 1, Skoru: %d\n", oyuncu1Skor);
    } else if (oyuncu2Skor > oyuncu1Skor) {
        printf("En sansli oyuncu: Oyuncu 2, Skoru: %d\n", oyuncu2Skor);
    } else {
        printf("Oyuncularin skorlari esittir.\n");
    }
}