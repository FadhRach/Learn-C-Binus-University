#include <stdio.h>

int main(){
	
	int a = 4;
	
//	printf("i++ : %d", a++);
//	printf("++i : %d", ++a);
//	printf("i-- : %d", a--);
//	printf("--i : %d", --a);
//	
//	int *anya = &a;
//	int **anyaa = &anya;
//	
//	
//	printf("%d", **anyaa);
//	

	for(int i = 1; i < 5; i++){
		printf("case%d : ", i);
		for(int j = 1; j < 5; j++){
			if (i == 2) {
				continue;
			}
			
			printf("%d", j);
			
		}
		printf("\n");
	}

	
	
	return 0;
}