#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int input();
int zarAt(int zarSayisi);
void sonucYazdir(int oyuncu1, int oyuncu2);

int main() {
    srand(time(NULL)); 

    int zarSayisi = input();

    
    printf("Oyuncu 1 zar atar: \n");
    int oyuncu1 = zarAt(zarSayisi);
    printf("Oyuncu 1 icin toplam: %d\n\n", oyuncu1);

    
    printf("Oyuncu 2 zar atar: \n");
    int oyuncu2 = zarAt(zarSayisi);
    printf("Oyuncu 2 icin toplam: %d\n\n", oyuncu2);

    
    sonucYazdir(oyuncu1, oyuncu2);

    return 0;
}

int input() {
    int x;
    printf("Kac zar atacaginizi yaziniz: ");
    scanf("%d", &x);

    if (x <= 0) {
        printf("Lutfen pozitif bir sayi giriniz.\n");
        input(); 
    }
    return x;
}

int zarAt(int zarSayisi) {
    int toplam = 0;
    for (int i = 1; i <= zarSayisi; i++) {
        int zar = (rand() % 6) + 1; 
        toplam += zar;
        printf("Zar %d: %d\n", i, zar);
    }
    return toplam;
}

void sonucYazdir(int oyuncu1, int oyuncu2) {
    printf("=== Sonuc ===\n");

    if (oyuncu1 > oyuncu2) {
        printf("En sansli oyuncu: Oyuncu 1, toplam: %d\n", oyuncu1);
    } else if (oyuncu2 > oyuncu1) {
        printf("En sansli oyuncu: Oyuncu 2, toplam: %d\n", oyuncu2);
    } else {
        printf("Oyuncularin toplam degerleri esittir.\n");
    }
}