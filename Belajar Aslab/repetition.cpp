#include <stdio.h>

int main() {
	int i = 0;
//	
//	for( i; i <= 10; ++i) { // pre/post increment didalam for loop tidak merubah apapun
//		printf("%d\n", i);
//	}


//	while(i <= 10) {
//		printf("%d\n", ++i); // pre increment didalam while berubah karena mengambil variable lalu ditambahkan dahulu baru dikeluarkan
//	}

//	do {
//		printf("%d\n", i++); // pre increment didalam while berubah karena mengambil variable lalu ditambahkan dahulu baru dikeluarkan
//	} while(i < 0);
	
	
	// LATSOL ================================================================
	
	puts("====================");
	puts("|| Validasi Input ||");
	puts("====================");
	
	int umur;
	char jenisKelamin;
	
	printf("Masukkan umur [>=0]: ");
	scanf("%d", &umur); getchar();
	
	while(umur < 0){
		printf("Masukkan umur [>=0]: ");
		scanf("%d", &umur); getchar();
	}
	
	
//	do {
//		printf("Masukkan umur [>=0]: ");
//		scanf("%d", &umur); getchar();
//	} while (umur < 0);
	
	do {
		printf("Masukkan Jenis Kelamin [L atau P]: ");
		scanf("%c", &jenisKelamin); getchar();
	} while(jenisKelamin != 'L' && jenisKelamin != 'P'); //ketika bukan L dan P maka stop perulangan
	
	if(jenisKelamin == 'L'){
		printf("Saya seorang laki-laki berumur %d!\n", umur);
	} else if (jenisKelamin == 'P'){
		printf("Saya seorang perempuan berumur %d!\n", umur);
	} else {
		printf("errorr!!!!!");
	}
	
	


	
	return 0;
}
