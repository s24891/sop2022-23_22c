#include <stdio.h>

int main(){
	int a=0;
	int wynik=0;
	do {
		a=0;
		scanf("%d",&a);
		if(a==0) break;
		wynik+=a;
	} while(a!=0);

	return wynik;
}
