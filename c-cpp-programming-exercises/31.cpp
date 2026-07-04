#include <stdio.h>
int x=0;
int input();
int max();
int min();

int main() {
int a=input();
int b=input();

printf("en buyuk deger: " ,max());
printf("en kucuk deger: " ,min());

}

int input(){
    printf("bir sayi giriniz: ");
    scanf("%d" ,&x);
    return x;
}

int max(int a, int b){
    


