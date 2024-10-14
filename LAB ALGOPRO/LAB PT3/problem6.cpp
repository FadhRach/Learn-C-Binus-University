#include <stdio.h>

int main() {
		
	int number, reversedNumber = 0, remainder;

    scanf("%d", &number);
	printf("%d\n", number%10);
    while (number != 0) {
        remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number /= 10;
    }

    printf("%d\n", reversedNumber);

    return 0;
}
