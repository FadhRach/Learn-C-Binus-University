#include <stdio.h>
#include <conio.h>

int main() {
	
//	printf("%s %10s\n", "Nasi goreng abah ken","Rp.80000");
//	printf("%s %10s\n", "Nasi Kuah Bermutu abah Ucup","Rp.80000");
//	putch('A');

//	int x, y;
	
//	scanf("%d %d", &x, &y);
//	printf("%d",x);
//	printf("%d",y);
	
//	char text[255];
//	
//	printf("Masukkan input: ");
//	scanf("%[^\n]", text);
//	printf("%s",text);

	char myChar1;
	char myChar2;
	char myChar3;
	
	printf("Input getChar() : ");
	myChar1 = getchar();	//nunggu enter
	printf("\nInput getCh() : ");
	myChar2 = getch();		//ga nunggu \n + ga di display
	printf("\nInput getChe() : ");
	myChar3 = getche();		//ga nunggu \n + di display
	
	printf("\ngetchar -> %c\n", myChar1);
	printf("getch -> %c\n", myChar2);
	printf("getche -> %c\n", myChar3);
	
	
	
	return 0;
}
