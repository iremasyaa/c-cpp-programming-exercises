#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileControl();
void fileCreate();
void fileRead();
void fileWrite();
void fileRemove();

char fileName[20]; 

int main() {
    int choice;

    printf("Dosya adini giriniz: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = '\0'; 

    while (1) {
        printf("\n****** DOSYA YONETIMI ******\n");
        printf("1. Dosyaya yaz\n");
        printf("2. Dosya yarat\n");
        printf("3. Dosya oku\n");
        printf("4. Dosya sil\n");
        printf("5. Dosya kontrol\n");
        printf("6. Cikis\n");
        printf("Seciminizi girin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fileWrite();
                break;
            case 2:
                fileCreate();
                break;
            case 3:
                fileRead();
                break;
            case 4:
                fileRemove();
                break;
            case 5:
                fileControl();
                break;
            case 6:
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim. Lutfen 1-6 arasinda bir secim yapin.\n");
        }
    }
}

// Dosya kontrol fonksiyonu
int fileControl() {
    FILE *ptr = fopen(fileName, "r");
    if (ptr == NULL) {
        printf("Dosya bulunamadi.\n");
        return 0;
    } else {
        printf("Dosya mevcut.\n");
        fclose(ptr);
        return 1;
    }
}

void fileWrite() {
    FILE *fpr = fopen(fileName, "a");
    char input[256];
    if (fpr == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    printf("Dosyaya yazmak istediginiz metni girin:\n");
    fgets(input, sizeof(input), stdin);
    fputs(input, fpr);
    printf("Metin dosyaya yazildi.\n");

    fclose(fpr);
}

void fileRead() {
    FILE *fpr = fopen(fileName, "r");
    char ch;

    if (fpr == NULL) {
        printf("Dosya okunamiyor veya mevcut degil.\n");
        return;
    }

    printf("Dosya icerigi:\n");
    while ((ch = fgetc(fpr)) != EOF) {
        putchar(ch);
    }
    fclose(fpr);
}

void fileCreate() {
    FILE *fpr = fopen(fileName, "w");
    if (fpr == NULL) {
        printf("Dosya olusturulamadi.\n");
        return;
    }
    printf("Dosya basariyla olusturuldu.\n");
    fclose(fpr);
}

void fileRemove() {
    if (remove(fileName) == 0) {
        printf("Dosya basariyla silindi.\n");
    } else {
        printf("Dosya silinemedi veya mevcut degil.\n");
    }
}
