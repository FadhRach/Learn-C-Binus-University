#include <stdio.h>

int main() {
	
    long long int N, dmg, total = 0, bonus;
	scanf ("%lld", &N);
	for (long long int i = 0; i < N; i++) {
		dmg = 100;
		bonus = (i * 50);
		total += dmg + bonus;
	}
	printf ("%lld\n", total);
	
	
	
    return 0;
}

