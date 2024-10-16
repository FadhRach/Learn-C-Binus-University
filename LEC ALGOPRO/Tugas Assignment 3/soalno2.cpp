#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	
	char kata[50];
	
	scanf("%[^\n]", kata);
	int pjgKata = strlen(kata);
//	printf("%s", strrev(kata)); //string reverse fungsi dari library string.h
	
	for(int i = pjgKata; i>=0; i--){
		printf("%c", kata[i]);
	}
	
	
//	int A[3][4]={1, 3, 2, 4,
//	 5, 7, 6, 8,
//	  9,11, 12 };
//	int B[3][3]={{1, 2}, {3, 4, 5} ,{ 7 }};
//	
//	printf("%d\n", A[1][1]);


//char agus;
//scanf("%c", &agus);
//
//printf("%c", toupper(agus));
//printf("%s", *str);

	
	
	return 0;
}