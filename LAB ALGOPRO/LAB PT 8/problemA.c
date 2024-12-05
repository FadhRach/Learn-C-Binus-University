#include <stdio.h>

int cari_fpb(int a, int b) {
    if (b == 0) {
        return a;
    }
    return cari_fpb(b, a % b);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        int A[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }

        int fpb = A[0];
        for (int j = 1; j < N; j++) {
            fpb = cari_fpb(fpb, A[j]);
        }

        printf("Case #%d: %d\n", i+1, fpb);
    }

    return 0;
}
