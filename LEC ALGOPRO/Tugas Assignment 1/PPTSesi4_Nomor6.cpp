#include <stdio.h>
	
int main() {
	float assignment;
	float midexam;
	float finalexam;
	float finalscore;
	
	printf("====== Calculate Final Score Program ======\n");
	printf("Input the Assignment Score: ");
	scanf("%f", &assignment);
	printf("Input the Mid Exam Score: ");
	scanf("%f", &midexam);
	printf("Input the Final Exam Score: ");
	scanf("%f", &finalexam);
	
	finalscore = 0.2*assignment + 0.3*midexam + 0.5*finalexam;
	
	printf("Final Score = %.2f\n", finalscore);
	
	return 0;
}
