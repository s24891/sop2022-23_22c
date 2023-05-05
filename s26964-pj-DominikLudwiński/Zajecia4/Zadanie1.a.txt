#include <stdio.h>

int main(){
	int a=0;
	int wynik=0;
	printf("By zakonczyc dzialanie programu podaj 0\n");
	do{
		printf("Podaj liczbe:\n");
		scanf("%d",&a);
		wynik = wynik + a;
	}while(a != 0);

	printf("Wynik: %d\n",wynik);
	return 0;
}
