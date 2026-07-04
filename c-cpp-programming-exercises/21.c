#include <stdio.h>

int main() {
   int num;
   int fact = 1;

   printf("Hangi sayini faktoriyelini hesaplayalim?: \n");
   scanf("%d", &num);

   for( num ; num>= 2 ; num--) {    
    fact *= num;
   }

   printf("%d Girilen sayinin faktoriyeli = %d\n", num, fact);

}
