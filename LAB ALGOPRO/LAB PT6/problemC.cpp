#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T); getchar();

    for (int i = 0; i < T; i++) {
        char s[100001];
        int hurufTotal = 0;
        int sudahDihitung[26] = {0};

        scanf("%s", s);

        int pjgKata = strlen(s);

        for (int j = 0; j < pjgKata; j++) {
            int idx = s[j] - 'a';
            if (sudahDihitung[idx] == 0) {
                hurufTotal++;
                sudahDihitung[idx] = 1;
            }
        }
        if (hurufTotal % 2 == 0) {
            printf("Case #%d: Yay\n", i + 1);
        } else {
            printf("Case #%d: Ewwww\n", i + 1);
        }
    }

    return 0;
}
