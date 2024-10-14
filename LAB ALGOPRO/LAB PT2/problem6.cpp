#include <stdio.h>
#include <string.h>

int main() {
	char nama[100], id[10];
	int pn,pi;
	
	scanf("%[^\n]s", nama); getchar();
	scanf("%s", id); getchar();
	
	pn = strlen(nama);
	pi = strlen(id);
	
	printf("%c", nama[0]);
	printf("%c", nama[pn - 1] - 32);
	printf("%c", id[0]);
	printf("%c", id[pi / 2]);
	printf("%c", id[pi - 1]);

    return 0;
}

