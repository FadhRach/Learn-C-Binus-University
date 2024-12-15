#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        char s[101];
        scanf("%s", s);

        int panjang = strlen(s);

        if (panjang % 2 != 0) {
            printf("NO\n");
        } else {
            int separuh = panjang / 2;
            int isPair = 1;

            for (int i = 0; i < separuh; i++) {
                if (s[i] != s[i + separuh]) {
                    isPair = 0;
                    break;
                }
            }

            printf(isPair ? "YES\n" : "NO\n");
        }
    }

    return 0;
}