#include <stdio.h>

int main() {
	
	const int ttp = 3;
	int a, b, c, d, e, f;
	
	scanf("%d", &ttp); getchar();
	scanf("%d %d", &a, &b); getchar();
	scanf("%d %d", &c, &d); getchar();
	scanf("%d %d", &e, &f); getchar();
	
	printf("%d\n", (a/b)<<b);
	printf("%d\n", (c/d)<<d);
	printf("%d\n", (e/f)<<f);
	
	
	return 0;
}
