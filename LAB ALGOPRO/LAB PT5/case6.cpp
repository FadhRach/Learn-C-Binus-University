#include <stdio.h>
#include <string.h>

int main() {
	
	int N;
	
	scanf("%d", &N); getchar();
	
	char S[1000];
	for (int i = 0; i < N; i++) {
        scanf(" %[^\n]", S);
        
        int len = strlen(S);

        printf("Case #%d : ", i + 1);
        for (int j = len - 1; j >= 0; j--) {
            printf("%c", S[j]);
        }
        printf("\n");
    }

	return 0;
}