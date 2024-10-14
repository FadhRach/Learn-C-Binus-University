#include <stdio.h>

int main() {
	float suhu;
	
	printf("Input suhu dalam celcius: ");
	scanf("%f", &suhu);
	
	printf("Reamur : %.2f\n", suhu*4/5);
	printf("Fahrenheit: %.2f\n", (suhu*9/5)+32 );
	printf("Kelvin: %.2f\n", suhu+273);
	
	return 0;
}
