#include <stdio.h>

int main() {
    int T;
    int N;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        
        int jumlahKolom[N];
        
        for (int j = 0; j < N; j++) {
            jumlahKolom[j] = 0;
        }
        
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                int elemen;
                scanf("%d", &elemen);
                jumlahKolom[k] += elemen;
            }
        }

        printf("Case #%d:", i + 1);
        for (int j = 0; j < N; j++) {
            printf(" %d", jumlahKolom[j]);
        }
        printf("\n");
    }

    return 0;
}
