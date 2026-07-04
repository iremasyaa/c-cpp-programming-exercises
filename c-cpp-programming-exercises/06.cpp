#include <stdio.h> 
int main () {
int sayilar[3], enbuyuk, enkucuk;

	printf("Lutfen sayilari giriniz:");

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &sayilar[i]);
	}
	enbuyuk = sayilar[0];
	for (int i = 0; i < 3; i++)
	{
		
		if (sayilar[i] > enbuyuk)
		{
			enbuyuk = sayilar[i];
		}
		
		enkucuk = sayilar[0];
		if (sayilar[i]<enkucuk)
		{
			enkucuk = sayilar[i];
		}
	}
	printf("En buyuk sayi: %d\n", enbuyuk);
	printf("En kucuk sayi: %d", enkucuk);
	
	return 0;
}