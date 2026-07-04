#include <stdio.h>

int main() {
    int midterm,final,average;

    printf("vize notu giriniz: \n");
    scanf("%d", &midterm);
    printf("final notu giriniz: \n");
    scanf("%d", &final);

    average = (midterm * 4/10) + (final * 6/10)/ 10;

    switch(average){

        case 5:
        printf("ortalamaniz: %d \n" ,average);
        printf("CC");
        break;

        case 6:
        printf("ortalamaniz: %d \n" ,average);
        printf("BC");
        break;
        
        case 7:
        printf("ortalamaniz: %d \n" ,average);
        printf("BB");
        break;

        case 8:
        printf("ortalamaniz: %d \n" ,average);
        printf("BA");
        break;
        
        case 9:
        printf("ortalamaniz: %d  \n" ,average);
        printf("AA");
        break;

        case 10:
        printf("ortalamaniz: %d \n",average);
        printf("AA");
        break;
        
        default:
        printf("ortalamaniz: %d \n" ,average);
        printf("FF");
        break;
    }

}