#include <stdio.h>

int main() {	

	float ipk = 5;
	char tombol = '*';
	
//	if(ipk >= 3.90) {
//		printf("IPK saya SummaCumLaude");
//	} else if(ipk >= 3.70) {
//		printf("IPK saya MagnaCumLaude");
//	} else if(ipk >= 3.50) {
//		printf("IPK saya CumLaude");
//	} else if(ipk >= 3.00) {
//		printf("IPK saya Biasa Aja");
//	} else {
//		printf("Maaf anda tidak lulus dari binus");
//	}

//	switch(tombol) {
//		case '+': {
//			printf("ini tambah");
//			break;
//		}
//		case '-': {
//			printf("ini kurang");
//			break;
//		}
//		default: {
//			printf("ini simbol lain");
//			break;
//		}
//	}

//	LATSOL============================================================================

	int angka;

	puts("============================");
	puts("|| Cek Angka Ganjil Genap ||");
	puts("============================");
	
	printf("Masukkan Angka: ");
	scanf("%d", &angka); getchar();
	printf("\n");
	
	if(angka % 2 == 0) {
		printf("Angka %d merupakan bilangan genap!\n", angka);
	} else {
		printf("Angka %d merupakan bilangan ganjil!\n", angka);
	}
	



	return 0;
}
