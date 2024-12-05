#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, M; // N jumlah makan, M jumlah kebahagiaan min
        scanf("%d %d", &N, &M);

        int H[N], W[N];
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &H[i], &W[i]); // H happiness, W Weight
        }

        long long minWeight = -1;

        for (int mask = 0; mask < (1 << N); mask++) {
            long long totalHappiness = 0, totalWeight = 0;

            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    totalHappiness += H[i];
                    totalWeight += W[i];
                }
            }

            if (totalHappiness >= M) {
                if (minWeight == -1 || totalWeight < minWeight) {
                    minWeight = totalWeight;
                }
            }
        }

        if (minWeight == -1) {
            printf("Case #%d: Impossible\n", t);
        } else {
            printf("Case #%d: %lld\n", t, minWeight);
        }
    }

    return 0;
}