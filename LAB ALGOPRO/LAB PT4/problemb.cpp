#include <stdio.h>

int main() {
	
	//Input terdiri dari 1 buah angka bulat N, ukuran matriks yang dimiliki lili. kemudian diikuti oleh N baris yang masing-masing terdiri N elemen 0 atau 1
	
	int N;
	scanf("%d", &N);
	int matrix [N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			do{
				scanf("%d", &matrix[i][j]); getchar();
			} while(matrix[i][j] != 0 && matrix[i][j] != 1);
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%d ", matrix[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}