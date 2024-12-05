#include <stdio.h>

int fibonacci(int F0, int F1, int K) {
    if (K == 0) return F0;
    if (K == 1) return F1;

    return fibonacci(F0, F1, K - 1) + fibonacci(F0, F1, K - 2);
}

int main() {
    int F0;
    int F1;
    int K;
    scanf("%d", &F0); getchar();
    scanf("%d", &F1); getchar();
    scanf("%d", &K); getchar();


    printf("%d\n", fibonacci(F0, F1, K));

    return 0;
}
