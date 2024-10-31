#include <stdio.h>

int countOnBits(int num) {
    int count = 0;
    while (num > 0) {
        count += (num & 1);  
        num >>= 1;           
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);  

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);  
        int arr[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int atLeast3OnBits = 0;  
        int lessThan3OnBits = 0;  

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int xorValue = arr[i] ^ arr[j];  
                int onBits = countOnBits(xorValue); 

                if (onBits >= 3) {
                    atLeast3OnBits++;  
                } else {
                    lessThan3OnBits++; 
                }
            }
        }

        printf("Case #%d: %d %d\n", t, atLeast3OnBits, lessThan3OnBits);
    }

    return 0;
}
