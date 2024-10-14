#include <stdio.h>

int main() {
	
	int a, b, c, d;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a); getchar();
		scanf("%d", &b); getchar();
		scanf("%d", &c); getchar();
		scanf("%d", &d); getchar();
		float sum;
		sum = ((2*a/1) + (4*b/2) + (6*c/3) + (4*d/4));
		printf ("%.2f\n", sum);
	}


		
    return 0;
}

