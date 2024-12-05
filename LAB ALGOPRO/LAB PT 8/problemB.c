#include <stdio.h>

int jobonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    return jobonacci(n - 1) + jobonacci(n - 3);
}

int main() {
    int N;
    scanf("%d", &N);

    printf("%d\n", jobonacci(N));

    return 0;
}
