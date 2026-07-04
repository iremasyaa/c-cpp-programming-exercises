#include <stdio.h>
#include <stdlib.h>

#define FILENAME "product.bat"
#define TEMPFILE "temp.bat"

struct product {
    int id;
    char name[20];
    float price;
    int stock;
};

void addProduct();
void updateProduct();
void deleteProduct();
void showProduct();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n*-*-* URUN YONETIMI *-*-*\n");
        printf("1. Urun Ekleme\n");
        printf("2. Urun Guncelleme\n");
        printf("3. Urun Silme\n");
        printf("4. Urun Goster\n");
        printf("5. Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                showProduct();
                break;
            case 5:
                exit(0);
            default:
                printf("Hatali giris! Tekrar deneyiniz.\n");
        }
    }
}

void addProduct() {
    struct product p;
    FILE *file = fopen(FILENAME, "ab");

    if (file == NULL) {
        printf("Dosya acilamadi ya da bulunamadi.\n");
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
    printf("Urun eklendi.\n");
}

void updateProduct() {
    struct product p;
    int id, newstock = 0;
    FILE *file = fopen(FILENAME, "rb+");

    if (file == NULL) {
        printf("Dosya acilamadi veya bulunamadi.\n");
        return;
    }

    printf("Guncellenecek urun ID'sini giriniz: ");
    scanf("%d", &id);

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

void deleteProduct() {
    struct product p;
    int id;
    int found = 0;

    FILE *file = fopen(FILENAME, "rb");
    FILE *temp = fopen(TEMPFILE, "wb");

    if (file == NULL || temp == NULL) {
        printf("Dosyalar acilamadi.\n");
        return;
    }

    printf("Silinecek urunun ID'sini giriniz: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(struct product), 1, file)) {
        if (p.id != id) {
            fwrite(&p, sizeof(struct product), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILENAME);
    rename(TEMPFILE, FILENAME);

    if (found) {
        printf("Urun basariyla silindi.\n");
    } else {
        printf("Urun bulunamadi.\n");
    }
}

void showProduct() {
    struct product p;
    FILE *file = fopen(FILENAME, "rb");

    if (file == NULL) {
        printf("Dosya acilamadi veya bulunamadi.\n");
        return;
    }

    printf("\n-*-*-*- URUN LISTESI -*-*-*-\n");
    while (fread(&p, sizeof(struct product), 1, file)) {
        printf("ID: %d | Ad: %s | Fiyat: %.2f | Stok: %d\n", p.id, p.name, p.price, p.stock);
    }

    fclose(file);
}