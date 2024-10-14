#include <stdio.h>

int main() {
	int T;
    scanf("%d", &T);
    long long int P[T], N[T];
    double hasil[T];

    for (int i = 0; i < T; i++) { 
        scanf("%lld %lld", &P[i], &N[i]); 
        hasil[i] = (P[i] / 100.0) * N[i];
    }

    for (int i = 0; i < T; i++) {
        printf("%.2f\n", hasil[i]);
    }

    return 0;
}
