
#include <stdio.h>
    int main(void) {
    int binlerb, yuzlerb, onlarb, birlerb, yenisayi;
    int num = 1234;

binlerb= num/1000;
yuzlerb= (num%1000)/100;
onlarb= ((num%1000)%100)/10;
birlerb= (((num%1000)%100)%10)/1;


printf("Binler basamagi %d \n",binlerb);
printf("Yuzler basamagi %d \n",yuzlerb);
printf("Onlar basamagi %d \n",onlarb);
printf("Birler basamagi %d \n",birlerb);

printf("Eski sayi= %d \n", num);

printf("Yeni sayi= %d%d%d%d", birlerb, onlarb, yuzlerb, binlerb);

}