#include <stdio.h>

int main() {
	int loop = 1;
	int input;
	
//	while(loop){
//		puts("1. Login");
//		puts("2. Register");
//		puts("3. Exit");
//		printf(">>");
//		
//		
//		scanf("%d", &input); getchar();
//		
//		switch(input){
//			case 1:
//				printf("This is login page\n");
//				break;
//			case 2:
//				printf("This is register page\n");
//				int age;
//				break;
//			case 3:
//				printf("Exit..\n");
//				loop = 0;
//				break;
//			default:
//				printf("Invalid option, Press enter to continue ?????????????????!\n");
//				break;
//		}
//	}

	

//	for(int i = 1, j = 10; i <= 10, j > 5; i++, j--){
//		printf("%d %d\n", i, j);
//		
//	}

//	for(int i = 1; i <= 5; i++){
//		for(int j = 1; j <= 5; j++){
//			printf("*");
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for(int i = 1; i <= 5; i++){
//		for(int j = 1; j<=i; j++){
//			printf("*");
//		}
//		printf("\n");	
//	}
//	printf("\n");
//	for(int i = 1; i <= 5; i++){
//		for(int j = 5; j>=i; j--){
//			printf("*");
//		}
//		printf("\n");	
//	}
	
	// BREAK VS CONTINUE
	
	for(int i = 0; i < 10; i++){
		if(i==5) break;
		printf("i: %d\n", i);
	}
	puts("");
	
	
	
	
	return 0;
}