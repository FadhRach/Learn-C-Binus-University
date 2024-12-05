#include <stdio.h>
#include <string.h>

int main() {  
    int T, A, B, digit_A, digit_B, sum, result, digit; 
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B); 
        result = 0; 
        digit = 1;

        while (A > 0 || B > 0) {
            digit_A = A % 10;
            digit_B = B % 10;

            sum = (digit_A + digit_B) % 10;
            result = result + (sum * digit);

            A = A / 10; 
            B = B / 10;
            digit = digit * 10;
        }
        printf("Case #%d: %d\n", i + 1, result);
    }

    return 0;
}
