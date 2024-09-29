#include <stdio.h>

int main() {
	
//	int a[5] = {4, 15, 7, 9, 10};
//	a[2] = 27;
//	
//	printf("Nilai array: %d\n", a[2]);

//	int m[4][4] = 
//	{
//		{1, 0, 1, 1},
//		{1, 1, 1, 0},
//		{1, 1, 1, 0},
//		{0, 1, 1, 1}		
//	};
//	
//	m[3][2] = 1;
//	printf("Nilai array 2D baris ke 4, kolom ke 3: %d\n", m[3][2]);

	int a = 10;
	int*p = &a;
	
	*p = 15;
	
	printf("Nilai variabel a: ")

	


//	LATSOL ====================================================================
	
//	int m1[3][3];
//	int m2[4][4];
//	int pilih;
//	int total;
//	
//	do{
//		puts("Pilih ukuran Matriks (1/2):");
//		puts("1. 3x3");
//		puts("2. 4x4");
//		printf("Pilih: ");
//		scanf("%d", &pilih); getchar();
//	} while (pilih != 1 && pilih != 2);
//	
//	if(pilih == 1){
//		for(int i = 0; i < 3; i++){
//			for(int j = 0; j < 3; j++){
//				printf("Masukkan matriks baris ke-%d kolom ke-%d: ", i+1, j+1);
//				scanf("%d", &m1[i][j]); getchar();
//				total += m1[i][j];	
//			}
//		}
//	} else if(pilih == 2) {
//		for(int i = 0; i < 4; i++){
//			for(int j = 0; j < 4; j++){
//				printf("Masukkan matriks baris ke-%d kolom ke-%d: ", i+1, j+1);
//				scanf("%d", &m2[i][j]); getchar();
//				total += m2[i][j];
//			}
//		}
//	} else{
//		printf("error!");
//	}
//	
//	
//	//===========================
//	printf("Hasil matriks: \n");
//	if(pilih == 1){
//		for(int i = 0; i < 3; i++){
//			printf("|");
//			for(int j = 0; j < 3; j++){
//				printf("%d ", m1[i][j]);
//			}
//			printf(" |\n");
//		}
//		printf("hasil matriks: %d", m1);
//	} else if(pilih == 2) {
//		for(int i = 0; i < 4; i++){
//			printf("|");
//			for(int j = 0; j < 4; j++){
//				printf("%d ", m2[i][j]);
//			}
//			printf(" |\n");
//		}
//
//	} else{
//		printf("error!");
//	}
//	printf("Sum matriks : %d\n", total);

	
	
	return 0;
}
