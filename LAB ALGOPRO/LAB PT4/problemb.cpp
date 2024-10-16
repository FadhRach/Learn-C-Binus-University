#include <stdio.h>

int main() {
	
	//Input terdiri dari 1 buah angka bulat N, ukuran matriks yang dimiliki lili. kemudian diikuti oleh N baris yang masing-masing terdiri N elemen 0 atau 1
	
	int N;
	scanf("%d", &N);
	int matrix [N][N];
	int transpose[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &matrix[i][j]); getchar();
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			transpose[j][i] = matrix[i][j];
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%d", transpose[i][j]);
			if(j == N -1){
				continue;
			}
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}