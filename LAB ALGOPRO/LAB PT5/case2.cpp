#include <stdio.h>

int main() {
	
	int T;
	scanf("%d", &T);
	
	int N[T];
	
//	input
	for(int i = 0; i < T; i++){
		scanf("%d", &N[i]);
	}
	
	
// output
	for (int i = 0; i < T; i++) {
    printf("Case #%d:\n", i + 1);
    
    for (int j = 1; j <= N[i]; j++) {
        for (int k = 1; k <= N[i]; k++) {
        	if ((N[i] - j) < k) {
				if ((j % 2) != (k % 2 == 0)) {
					printf ("*");
				} else {
					printf ("#");
				}
			} else {
				printf (" ");
			}
        }
        printf("\n");
    }

}

	
	
	return 0;
}