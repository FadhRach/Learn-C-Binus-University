#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 3 == 0) return 10;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
