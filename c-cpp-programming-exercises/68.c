#include <stdio.h>
#include <stdlib.h>

#define FILENAME "product.bat"

struct product {
    int id;
    char name[20];
    float price;
    int stock;
};

void addproduct();
void updateproduct();
void showproduct();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n** URUN YONETIMI **\n");
        printf("1. Urun Ekleme\n");
        printf("2. Urun Guncelleme\n");
        printf("3. Urun Goster\n");
        printf("4. Cikis\n");
        printf("Secim yapiniz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addproduct();
                break;
            case 2:
                updateproduct();
                break;
            case 3:
                showproduct();
                break;
            case 4:
                exit(0);
            default:
                printf("Hatali giris yaptiniz. Tekrar deneyiniz.\n");
        }
    }
}

void addproduct() {
    struct product p;
    FILE *file = fopen(FILENAME, "ab");

    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    printf("Urun ID: ");
    scanf("%d", &p.id);
    printf("Urun Adi: ");
    scanf("%s", p.name);
    printf("Urun Fiyati: ");
    scanf("%f", &p.price);
    printf("Urun Miktari: ");
    scanf("%d", &p.stock);

    fwrite(&p, sizeof(struct product), 1, file);
    fclose(file);
    printf("Urun basariyla eklendi.\n");
}

void updateproduct() {
    struct product p;
    int id, newstock = 0;
    FILE *file = fopen(FILENAME, "rb+");

    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    printf("Guncellenecek urun ID'sini girin: ");
    scanf("%d", &id);

    fseek(file, 0, SEEK_SET);
    while (fread(&p, sizeof(struct product), 1, file)) {
        if (p.id == id) {
            printf("Yeni stok miktari: ");
            scanf("%d", &newstock);
            p.stock = newstock;

            fseek(file, -sizeof(struct product), SEEK_CUR);
            fwrite(&p, sizeof(struct product), 1, file);
            printf("Urun stok bilgisi guncellendi.\n");
            fclose(file);
            return;
        }
    }

    printf("Urun bulunamadi.\n");
    fclose(file);
}

void showproduct() {
    struct product p;
    FILE *file = fopen(FILENAME, "rb");

    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    printf("\n--- URUN LISTESI ---\n");
    while (fread(&p, sizeof(struct product), 1, file)) {
        printf("ID: %d | Ad: %s | Fiyat: %.2f | Stok: %d\n", p.id, p.name, p.price, p.stock);
    }

    fclose(file);
}
