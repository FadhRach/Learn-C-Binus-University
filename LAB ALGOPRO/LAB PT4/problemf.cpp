#include <stdio.h>
int main() {
	
	int T;
	scanf("%d", &T); getchar();
	
	int A[T];
	int B[T];
	
	for(int i = 0; i < T; i++){
		scanf("%d %d", &A[i], &B[i]); getchar();
	}
	
	for(int i = 0; i < T; i++){
		printf("Case #%d: ", i + 1);
		int a = A[i];
		int b = B[i];
		
		for(int j = 0; j < 1000; j++) {
			if (a == b){
				printf("%d\n", a);
				break;
			}
			
			a += 4;
			b -= 5;
		}
		
		if (a != b) {
			printf("Possiblen't\n");
		}
	}
	
		
	
	return 0;
}