#include <stdio.h>

int main(){
	
	int satu;
	int dua;
	int tiga;
	
	scanf("%d", &satu); getchar();
	scanf("%d", &dua); getchar();
	scanf("%d", &tiga); getchar();
	
	printf("%d\n", (satu/10)%10);
	printf("%d\n", (dua/10)%10);
	printf("%d\n", (tiga/10)%10);
	
	
	
	
	return 0;
}
