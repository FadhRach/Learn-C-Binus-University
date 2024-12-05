#include <stdio.h>
#include <string.h>

int main() {
    char kata[50];
    int jumlahA = 0;

    scanf("%[^\n]", kata);
    
    int pjgKata = strlen(kata);

    for (int i = 0; i < pjgKata; i++) {
        if (kata[i] == 'a' || kata[i] == 'A') {
            jumlahA++;
        }
    }

    if (jumlahA == 0) {
        printf("Gratis\n");
    } else {
        printf("%d\n", jumlahA * 1000);
    }

    return 0;
}
