#include <stdio.h>

int main() {
	
	printf("hello world\n");
	printf("hello world\n");
	
	// single-line comment
	
	/*
	multi line comment
	*/
	
	//variable
	/*
		char -> a..z A..Z 0..9 ~!@#$%^&*()_+
		int -> 
		float -> 3,14
		double ->
		String -> arr of char
		bool
	*/
	
//	int umur; //deklarasi
//	umur = 19; //inisialisasi
//	double tinggi = 156.45; //deklarasi + inisialisasi
//	
//	printf("Halo nama saya Willian\n");
//	printf("Umur saya %d, Tinggi saya %lf\n", umur, tinggi);

	char nama[10];
	double tinggi;
	int aura;
	char nilai;
	float ipk;
	
//	input scanf("");
	scanf("%s", &nama); getchar();
	scanf("%lf", &tinggi); getchar();
	scanf("%d", &aura); getchar();
	scanf("%c", &nilai); getchar();
	scanf("%f", &ipk); getchar();

	printf("Halo nama saya %s\n", nama);
	printf("Tinggi saya %lf\n", tinggi);
	printf("Aura saya sebesar %d\n", aura);
	printf("Nilai Algoritma saya %c\n", nilai);
	printf("IPK saya %f\n", ipk);
	printf("Dingin tetapi tidak kejam");
	
	
	return 0;
}
