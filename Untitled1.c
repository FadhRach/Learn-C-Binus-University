#include <stdio.h>

int main() {
	
	char nama[50];
	
//	printf("Masukkan nama: ");
//	gets(nama);
//	
//	printf("%s", nama);

	printf("Masukkan nama: ");
	scanf("%[^\n]", &nama);
	
	printf("%s", nama);
	
	return 0;
}
