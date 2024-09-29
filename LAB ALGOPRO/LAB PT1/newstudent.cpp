#include <stdio.h>

int main() {
	
	char N [100];
	int A;
	int U;
	
	scanf("%[^\n]", N); getchar();
	scanf("%d %d", &A, &U);
	
	printf("Name: %s\n", N);
	printf("NIS: %d\n", A);
	printf("Age: %d\n", U);
	
	
	return 0;
}
