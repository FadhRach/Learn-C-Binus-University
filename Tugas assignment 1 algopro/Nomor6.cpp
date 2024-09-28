#include <stdio.h>
	//	Create a program in C to receive input from standard input (keyboard) for the following data:
	//	-Assignment Score
	//	-Mid Exam Score
	//	-Final Exam Score
	//
	//	Calculate and display Final Score using :
	//	Final Score = 20%*Assignment + 30%*Mid + 50%*Final
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
	
	printf("Final Score = %f\n", finalscore);
	
	
	return 0;
}
