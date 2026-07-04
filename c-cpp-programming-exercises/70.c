#include <stdio.h>
#include <stdlib.h>



int fileControl();
void fileCreate();
void fileRead();
void fileWrite();
void fileRemove();


int main() {
    int choice;
    printf("Dosya islemini giriniz: ");
    scanf("%s", fileName);

char fileName[20] = "output.txt";
    scanf("%s", fileName);

    while(1) {
        printf("******DOSYA YONETIMI******");
        printf("1, Dosya yazma");
        printf("2, Dosya yarat");
        printf("3, Dosya oku");
        printf("4, Dosya sil");
        printf("5, Dosya kontrol");
        printf("6, Cikis");
        scanf("%d" , &choice);


        switch (choice) {
        case 1:
             fileRead();
             break;
        case 2:
             fileCreate();
            break;
        case 3:
            fileRead();
            break;
        case 4:
            break;
             fileRemove();
        case 5:
            fileControl();
            break;
        case 6:
            printf("Programdan cikiliyor...\n");
            return 0;
        default:
            printf("Gecersiz secim. Lutfen 1-6 arasinda bir deger girin.\n");
        }

    }

}



int fileControl() {
    FILE *ptr;

    if(ptr = NULL){
        printf("Dosya bulunamadi.");
} else {
        printf("Dosya mevcut."); }

}

void fileWrite() {
        FILE *fpr = fopen(fileName, "a");
        char input[256];
    
        if (fpr == NULL) {
            printf("Dosya acilamadi.\n");
            return;
        }
    
        printf("Dosyaya yazmak istediginiz metni girin (satir sonu icin ENTER):\n");
        getchar();
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
        printf("Dosya basariyla olusturuldu.\n", fileName);
        fclose(fpr);
    }

    void fileRemove() {
        if (remove(fileName) == 0) {
            printf("Dosya basariyla silindi.\n", fileName);
        } else {
            printf("Dosya silinemedi veya mevcut degil.\n");
        }
    }







