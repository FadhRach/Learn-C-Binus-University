#include <stdio.h>
#include <math.h>

int main() {
	
	//ASSIGNMENT OPERATOR (=)
//	int x = 11; //baca dari kanan ke kiri
//	
//	int a,b,c,d;
//	a = b = c = d = 17;
//	int num1 = 10;
//	int num2 = b;
//	int num3 = 10 + x;
//	int num4 = pow(2, 2);
//	
//	printf("%d\n", x);
//	printf("%d %d %d %d\n", a, b, c, d);
//	printf("%d %d %d %d\n", num1, num2, num3, num4);


	//ARITHMETIC OPERATOR + - / * % ++ -- ()
//	int a = 10, b = 5;
//	
//	printf("%d\n", a + b);
//	printf("%d\n", a - b);
//	printf("%d\n", a * b);
//	printf("%d\n", a / b);
//	printf("%d\n", a % b);
//	printf("%d\n", (a + b) * 2);
//	printf("%d\n", a++);
//	printf("%d\n", ++a);
//	printf("%d\n", a--);
//	printf("%d\n", --a);

//	a*= 10 + 1;
//	a = a * (10 + 1);
//	printf("%d\n", a);
	
	//RELATIONAL OPERATORS == != < > <= >= ?:
//	(5 == 10) ? printf("Hai\n") : printf("Hai gengs\n");
//	(5 != 10) ? printf("Hai\n") : printf("Hai gengs\n");
//	(5 < 10) ? printf("Hai\n") : printf("Hai gengs\n");
//	(5 > 10) ? printf("Hai\n") : printf("Hai gengs\n");
//	(5 <= 10) ? printf("Hai\n") : printf("Hai gengs\n");
//	(5 >= 10) ? printf("Hai\n") : printf("Hai gengs\n");
	
	
	//LOGICAL OPERATOR
	(1 && 1) ? printf("True\n") : printf("False\n");
	(1 && 0) ? printf("True\n") : printf("False\n");
	(0 && 1) ? printf("True\n") : printf("False\n");
	(0 && 0) ? printf("True\n") : printf("False\n");
	
	(1 || 1) ? printf("True\n") : printf("False\n");
	(1 || 0) ? printf("True\n") : printf("False\n");
	(0 || 1) ? printf("True\n") : printf("False\n");
	(0 || 0) ? printf("True\n") : printf("False\n");
	
	
	(!1) ? printf("True\n") : printf("False\n");
	(!0) ? printf("True\n") : printf("False\n");
	return 0;
}
