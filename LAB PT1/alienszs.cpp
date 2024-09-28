#include <stdio.h>

int main() {
	
	//setiap baris terdiri dari tepat 3 buah kata yang dipisahkan dengan spasi
	//setiap kata terdiri dari huruf kecil dan kapital yang memiliki paling banyak 20 karakter
	
	//ex:
	//input:
	//Hello Binusian Freshmen
	//Welcome to Binus
	
	//output:
	//Helloszs Binusianszs Freshmenszs
	//Welcomeszs toszs Binusszs
	
	char kata1 [20];
	char kata2 [20];
	char kata3 [20];
	char kata4 [20];
	char kata5 [20];
	char kata6 [20];
	
	scanf("%s %s %s", &kata1, &kata2, &kata3); getchar();
	scanf("%s %s %s", &kata4, &kata5, &kata6); getchar();
	
	printf("%sszs %sszs %sszs\n", kata1, kata2, kata3);
	printf("%sszs %sszs %sszs\n", kata4, kata5, kata6);
	
	
	return 0;
}
