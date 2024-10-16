#include <stdio.h>
int main() {
	
	int T, N;
	scanf("%d", &T); getchar();
	
	for(int i = 0; i < T; i++){
		scanf("%d", &N);
		printf("Case #%d:\n", i + 1);
		for(int i = 1; i <= N; i++){
			if((i % 3 == 0 || i % 5 == 0) && i % 15 != 0){
				printf("%d Jojo\n", i);
			} else {
				printf("%d Lili\n", i);
			}
		}
	}
	
		
	
	return 0;
}