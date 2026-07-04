#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;
Node* head = NULL;

void yazdir();
void basaEkle(int veri);
void arayaEkle(int veri, int sira);
void sonaEkle(int veri);
void dugumSil();

int main(){
    int secim, veri, sira;

    while (1) {
        printf("\n---Menu---\n");
        printf("1. Listeyi goruntule\n");
        printf("2. Basa eleman ekle\n");
        printf("3. Araya eleman ekle\n");
        printf("4. Sona eleman ekle\n");
        printf("5. Dugum sil\n");
        printf("6. Cikis yap\n");
        printf("Secim yapiniz: ");
        scanf("%d", &secim);

        switch (secim){
            case 1:
                yazdir();
                break;
            case 2:
                printf("Eleman girin: ");
                scanf("%d", &veri);
                basaEkle(veri);
                break;
            case 3:
                printf("Eleman girin: ");
                scanf("%d", &veri);
                printf("Hangi indekse ekleme yapilsin: ");
                scanf("%d", &sira);
                arayaEkle(veri, sira);
                break;
            case 4:
                printf("Eleman girin: ");
                scanf("%d", &veri);
                sonaEkle(veri);
                break;
            case 5:
                dugumSil();
                break;
            case 6:
                printf("Cikis yapiliyor.\n");
                exit(0);
            default:
                printf("Gecersiz secim yapildi.\n");
                break;
        }
    }

    return 0;
}

void yazdir(){
    Node* temp = head;

    printf("Liste: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void basaEkle(int veri){
    Node* yeni = (Node*)malloc(sizeof(Node));

    yeni->data = veri;
    yeni->next = head;

    head = yeni;
}

void arayaEkle(int veri, int sira){
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->next = NULL;
    if(sira == 0){
        basaEkle(veri);
        return;
    }
    Node* temp = head;
    for(int i = 0; i < sira - 1; i++){
        if(temp == NULL){
            printf("Girilen deger, liste boyutundan buyuktur!\nEkleme yapilamadi.\n");
            free(yeni);
            return;
        }
        temp = temp->next;
    }
    yeni->next = temp->next;
    temp->next = yeni;

    printf("%d. indekse %d degeri eklendi.\n", sira, veri);
}

void sonaEkle(int veri){
    Node* yeni = (Node*)malloc(sizeof(Node));
    
    yeni->data = veri;
    yeni->next = NULL;

    if(head == NULL){
        head = yeni;
        printf("%d degeri, listenin sonuna eklendi.\n", veri);
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = yeni;
    printf("%d degeri, listenin sonuna eklendi.\n", veri);
}

void dugumSil(){
    int sira;
    printf("Silmek istediginiz dugumun indeksini girin: ");
    scanf("%d", &sira);

    if (head == NULL) {
        printf("Liste bos, silinecek eleman yok.\n");
        return;
    }

    Node* temp = head;

    if (sira == 0) {
        head = head->next;
        printf("0. indeksteki (%d) dugum silindi.\n", temp->data);
        free(temp);
        return;
    }

    for (int i = 0; i < sira - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Gecersiz indeks!\n");
            return;
        }
        temp = temp->next;
    }

    Node* silinecek = temp->next;
    if (silinecek == NULL) {
        printf("Gecersiz indeks!\n");
        return;
    }

    temp->next = silinecek->next;
    printf("%d. indeksteki (%d) dugum silindi.\n", sira, silinecek->data);
    free(silinecek);

    yazdir();
}
