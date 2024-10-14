#include <stdio.h>

int main() {
	char x[40];
	char ss1[40];
	char ss2[40];
	scanf("%s %s",ss1,ss2);
//	x = ss1 ss2;
	
	printf("%s", ss1);
	printf("%s", ss2);
//	printf("%s", x);

//	a. What is ss1 and ss2, if the input from keyboard is ”Good morning everyone”  ?
//	- ss1 is "Good" and ss2 is "morning"

//	b. What is x if the input : ”Class 1PAT”  ?
//	- ss1 akan terisi "Class" dan ss2 akan terisi "1PAT" lalu di masukkan ke x hasilnya "Class 1PAT"

	
	return 0;
}
