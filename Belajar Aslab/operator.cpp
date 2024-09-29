#include <stdio.h>

//operator
int main() {
//	int a = 10;
//	int b = 3;
//	printf("postincrement: %d\n", a++); // ambil a dari variable= 10 (a=10 tampilkan) baru ditambah 1  untuk a selanjutnya 11
//	printf("preincrement: %d\n", ++a); // ambil a sebelumnya= 11 ++a = 1 + 11 = 12 tambahkan dlu baru dimasukkan dan (ditampilkan ke a=12)
//	
//	printf("postdecrement: %d\n", a--); // ambil a sebelumnya= 12 (12=a tampilkan) lalu -- = 12-1 = 11, untuk a selanjutnya 11
//	printf("predecrement: %d\n", --a); // ambil a sebelumnya= 11 lalu kurangi dlu 11-1 = 10 baru (tampilkan a= 10)
	
	//LATSOL
	
	char namaBarang [100];
	int harga;
	int jumlah;
	
	
	puts("========================");
	puts("| Simulasi Jual Barang |");
	puts("========================");
	
	printf("Masukkan Nama Barang: ");
	scanf("%[^\n]", namaBarang); getchar();
	printf("Masukkan Harga Barang: ");
	scanf("%d", &harga); getchar();
	printf("Masukkan Jumlah Barang: ");
	scanf("%d", &jumlah); getchar();
	
	printf("Jadi barang yang terjual adalah %d %s dan mendapat keuntungan %d!\n", jumlah, namaBarang, harga * jumlah );
	
	
	
	
	
	
	
	return 0;
}
