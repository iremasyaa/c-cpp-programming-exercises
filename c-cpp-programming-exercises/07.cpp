#include <stdio.h>
main()  {

    int faktoriyel = 1; 
    int sayi;
    
    printf("Bir sayi giriniz: ");
    scanf("%d",&sayi);
    
    while(sayi > 0){
        faktoriyel = faktoriyel * sayi;
        sayi--;
    }
    printf("Faktoriyel = %d",faktoriyel);
}