#include <stdio.h>

int main() {
	
	char name[40];
	int nim;
	char gender;
	printf("Name: "); scanf("[^\n]", name);
	printf("StudentNim: "); scanf("%d", &nim);
	printf("Gender (M/F): "); gender=getchar();
	
	return 0;
}
