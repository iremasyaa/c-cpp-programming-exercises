#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time fonksiyonunun prototipini içerir

// Oyunun durumunu temsil eden sabitler
enum Durum {DEVAM, KAZANDI, KAYBETTI}; 

// Zar atma fonksiyonunun prototipi
int zarAt(void); 

int main(void) {
    srand(time(NULL)); // Rastgele sayı üreticisini mevcut zamana göre başlat

    int hedefPuan = 0; // Oyuncunun kazanması için bu puanı yapması gerekiyor
    enum Durum oyunDurumu = DEVAM; // Oyun durumu (DEVAM, KAZANDI veya KAYBETTI)
    int toplam = zarAt(); // İlk zar atışı

    // Zarların toplamına göre oyunun durumunu belirle
    switch (toplam) {
        case 7: // 7 ile kazanır
        case 11: // 11 ile kazanır
            oyunDurumu = KAZANDI;
            break;

        case 2: // 2 ile kaybeder
        case 3: // 3 ile kaybeder
        case 12: // 12 ile kaybeder
            oyunDurumu = KAYBETTI;
            break;

        default: // Puanı hatırla
            oyunDurumu = DEVAM; // Oyuncu zarlara devam etmeli
            hedefPuan = toplam; // Puanı hatırla
            printf("Hedef puan: %d\n", hedefPuan);
            break;
    }

    // Oyun tamamlanana kadar devam et
    while (oyunDurumu == DEVAM) { // Oyuncu zarlara devam etmeli
        toplam = zarAt(); // Zarları tekrar at

        // Oyunun durumunu belirle
        if (toplam == hedefPuan) { // Hedef puanı yaparak kazanır
            oyunDurumu = KAZANDI;
        } else if (toplam == 7) { // 7 atarak kaybeder
            oyunDurumu = KAYBETTI;
        }
    }

    // Kazanma veya kaybetme mesajını göster
    if (oyunDurumu == KAZANDI) { // Oyuncu kazandı mı?
        puts("Oyuncu kazandı!");
    } else { // Oyuncu kaybetti
        puts("Oyuncu kaybetti!");
    }

    return 0;
}

// Zar atma, toplamı hesaplama ve sonucu gösterme
int zarAt(void) {
    int zar1 = 1 + (rand() % 6); // 1 ile 6 arasında rastgele birinci zar
    int zar2 = 1 + (rand() % 6); // 1 ile 6 arasında rastgele ikinci zar

    // Bu zar atışının sonucunu göster
    printf("Oyuncu %d + %d = %d attı\n", zar1, zar2, zar1 + zar2);
    return zar1 + zar2; // Zarların toplamını döndür
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

enum Status {CONTINUE, WON, LOST}; // constants represent game status

int rollDice(void); // rollDice function prototype

int main(void) {
    srand(time(NULL)); // randomize based on current time

    int myPoint = 0; // player must make this point to win
    enum Status gameStatus = CONTINUE; // may be CONTINUE, WON, or LOST
    int sum = rollDice(); // first roll of the dice

    // determine game status based on sum of dice
    switch (sum) {
        case 7: // 7 is a winner
        case 11: // 11 is a winner
            gameStatus = WON;
            break;

        case 2: // 2 is a loser
        case 3: // 3 is a loser
        case 12: // 12 is a loser
            gameStatus = LOST;
            break;

        default: // remember point
            gameStatus = CONTINUE; // player should keep rolling
            myPoint = sum; // remember the point
            printf("Point is %d\n", myPoint);
            break;
    }

    // while game not complete
    while (gameStatus == CONTINUE) { // player should keep rolling
        sum = rollDice(); // roll dice again

        // determine game status
        if (sum == myPoint) { // win by making point
            gameStatus = WON;
        } else if (sum == 7) { // lose by rolling 7
            gameStatus = LOST;
        }
    }

    // display won or lost message
    if (gameStatus == WON) { // did player win?
        puts("Player wins");
    } else { // player lost
        puts("Player loses");
    }

    return 0;
}

// roll dice, calculate sum and display results
int rollDice(void) {
    int die1 = 1 + (rand() % 6); // pick random die1 value
    int die2 = 1 + (rand() % 6); // pick random die2 value

    // display results of this roll
    printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
    return die1 + die2; // return sum of dice
}
