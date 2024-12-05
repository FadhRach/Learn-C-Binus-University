#include <stdio.h>

int main() {
    char S[10001];
    char peta[] = {'o', 'i', 'r', 'e', 'a', 's', 'g', 't', 'b', 'p'};


    scanf("%10000[^\n]", S);

    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] >= '0' && S[i] <= '9') {
            S[i] = peta[S[i] - '0'];
        } else if (S[i] >= 'A' && S[i] <= 'Z') {
            S[i] += 32;
        }
    }

    printf("%s\n", S);

    return 0;
}