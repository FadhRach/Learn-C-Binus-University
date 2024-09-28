#include <stdio.h>

int main() {
	
	char nama[50];
	
	scanf("%[^\n]s", &nama);getchar();
	
	printf("\"Hello %s!  Welcome to C Programming!\"\n", nama);
	
	return 0;
}
