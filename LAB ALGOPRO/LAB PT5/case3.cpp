#include <stdio.h>

int main() {

    int T;
    long long int N, M, j, result, temp, count;

    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        scanf("%lld %lld", &N, &M);

        result = 0;
        count = 0;

        for (j = 0; j <= N; j += M) {
            if (j % M == 0) {
                if (count == 10) {
                    //Kelipatan terdekat saat dibagi M * 10
                    temp = N / (M * 10);
                    //Hasil dikali dengan kelipatan
                    result *= temp;
                    //N = sisa halaman
                    N %= M * 10 * temp;
                    //Mulai dari halaman pertama
                    j = 0;
                }

                else {
                    result += j % 10;
                } 
                count++;
            }
        }
        printf("Case #%d: %lld\n", i + 1, result);
    }

    return 0;
}