#include <stdio.h>

int main() {
		
	int T;
	scanf("%d", &T);
	int X[T];
	int P[T];
	for (int i = 1; i <= T; i++){
		scanf("%d %d", &X[i], &P[i]);
	}
	
	for (int i = 1; i <= T; i++){
		printf("%d\n", (X[i]>>P[i])&1);
	}
			
		
	return 0;
}
