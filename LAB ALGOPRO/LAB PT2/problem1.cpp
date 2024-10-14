#include <stdio.h>

int main(){
	
	char course_code[5][11];
	int startHour[5], endHour[5];
	int startMin[5], endMin[5];
	
	
	for (int i = 0; i < 5; i++){
		scanf("%s %d:%d-%d:%d", course_code[i], &startHour[i], &startMin[i], &endHour[i], &endMin[i]);
	}
	
	
	for (int i = 0; i < 5; i++){
		printf("%s %.2d:%.2d-%.2d:%.2d\n", course_code[i], startHour[i]-1, startMin[i], endHour[i]-1, endMin[i]);
	}
	
	return 0;
}
