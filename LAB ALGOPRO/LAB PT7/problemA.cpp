#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N); getchar();
        long int A[N], B[N];

        for (int j = 0; j < N; j++) {
            scanf("%ld", &A[j]); getchar();
        }

        for (int k = 0; k < N; k++) {
            scanf("%ld", &B[k]); getchar();
        }

        printf("Case #%d:", i + 1);
        for (int l = 0; l < N; l++) {
            printf(" %ld", A[l] - B[l]);
        }
        printf("\n");
    }

    return 0;
}
