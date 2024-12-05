#include <stdio.h>

int main() {
    int E, D;
    scanf("%d %d", &E, &D);

    // Enkripsi
    int digit[4];
    for (int i = 3; i >= 0; i--) {
        digit[i] = (E % 10 + 7) % 10;
        E /= 10;
    }
    printf("Encrypted: %d%d%d%d\n", digit[2], digit[3], digit[0], digit[1]); //2301

    // Dekripsi
    for (int i = 3; i >= 0; i--) {
        digit[i] = (D % 10);
        D /= 10;
    }
    int decrypted[4];
    decrypted[0] = (digit[1] + 3) % 10;
    decrypted[1] = (digit[0] + 3) % 10;
    decrypted[2] = (digit[3] + 3) % 10;
    decrypted[3] = (digit[2] + 3) % 10;

    printf("Decrypted: %d%d%d%d\n", decrypted[3], decrypted[2], decrypted[1], decrypted[0]); //3210
    return 0;
}
