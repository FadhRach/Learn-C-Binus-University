#include <stdio.h>

int main() {
	
//	int n;
//	scanf("%d", &n);
////	(n == 0) ? printf("True") : printf("False");
//	if(n == 1){
//		printf("angka 1");
//	}
//	if(n == 2){
//		printf("angka 2");
//	}
//	if(n == 3){
//		printf("angka 3");
//	}else{
//		printf("bukan angka 1, 2, 3");
//	}

	int choice;
	puts("1. Play");
	puts("2. Menu");
	puts("3. Exit");
	puts("=========================");
	
	printf("Masukkan Pilihan: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			printf("Playing game");
			break;
		case 2:
			printf("Menu game");
			break;
		case 3:
			printf("Exit...");
			break;		
	}
	return 0;
}