#include <stdio.h>

int main() {
	
	const int T = 3;
	float A1, A2, A3;
	
	scanf("%f", &T); getchar();
	
	scanf("%f", &A1); getchar();
	scanf("%f", &A2); getchar();
	scanf("%f", &A3); getchar();
	
	printf("%.2f %.2f %.2f\n", A1*4/5, A1*9/5+32, A1+273);
	printf("%.2f %.2f %.2f\n", A2*4/5, A2*9/5+32, A2+273);
	printf("%.2f %.2f %.2f\n", A3*4/5, A3*9/5+32, A3+273);
	
	
	return 0;
}
