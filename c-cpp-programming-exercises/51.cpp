#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Yemek {Pizza,Hamburger,Doner,Lahmacun};
enum Tatli {Baklava,Kunefe};

enum Yemek rastgeleYemekSec();
enum Tatli rastgeleTatliSec();

int main()
{
    srand(time(NULL));

    enum Yemek secilenYemek = rastgeleYemekSec();
    enum Tatli secilenTatli = rastgeleTatliSec();

    printf("Secilen Yemek: ");
    switch (secilenYemek)
    {
    case Pizza:
        printf("Pizza\n");
        break;
    case Hamburger:
        printf("Hamburger\n");
        break;
    case Doner:
        printf("Doner\n");
        break;
    case Lahmacun:
        printf("Lahmacun\n");
        break;
    }

    printf("Secilen Tatli: ");
    switch (secilenTatli)
    {
    case Baklava:
        printf("Baklava\n");
        break;
    case Kunefe:
        printf("Kunefe\n");
        break;
    }

    return 0;
}

enum Yemek rastgeleYemekSec()
{
    return (enum Yemek)(rand() % 4);
}

enum Tatli rastgeleTatliSec()
{
    return (enum Tatli)(rand() % 2);
}