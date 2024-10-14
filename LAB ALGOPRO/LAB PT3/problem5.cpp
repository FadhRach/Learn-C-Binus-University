#include <stdio.h>

int main() {
		
	long long int N, poin, total = 0, bonus;
	scanf ("%lld", &N);
	for (long long int i = 0; i < N; i++) {
		poin = 100;
		bonus = (i * 50);
		total += poin + bonus;
	}
	printf ("%lld\n", total);
		
	return 0;
}
