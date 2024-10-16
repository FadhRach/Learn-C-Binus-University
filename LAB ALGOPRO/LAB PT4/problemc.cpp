#include <stdio.h>

int main() {
	
	float num;
	scanf("%f", &num);
	
	int angka_2bel = (int)(num * 100) % 100; //192.753 = 19275.3 % 100 = 75
	
	int digit1 = angka_2bel / 10; // 75/10 7.5 = 7
	int digit2 = angka_2bel % 10;
	
	if(digit1 % 2 == digit2 % 2){
		printf("1\n");
	} else {
		printf("0\n");
	}
	return 0;
}