#include <stdio.h>
#include <string.h>

void awalanPanjang(char kamus[][100], int N, char hasil[]) {
    if (N == 0) {
        hasil[0] = '\0';
        return;
    }
    
    strcpy(hasil, kamus[0]);
    for (int i = 1; i < N; i++) {
        int j = 0;
        while (hasil[j] && kamus[i][j] && hasil[j] == kamus[i][j]) {
            j++;
        }
        hasil[j] = '\0';
    }
}

int main() {
    int N;
    printf("Masukkan jumlah kata: ");
    scanf("%d", &N);

    char kamus[N][100];  
    char hasil[100];

    printf("Masukkan kata-kata:\n");
    for (int i = 0; i < N; i++) {
        printf("kata ke [%d]: ", i + 1);
        scanf("%s", kamus[i]);
    }

    awalanPanjang(kamus, N, hasil);
    printf("Awalan terpanjang dari input: \"%s\"\n", hasil);

    return 0;
}




    // Dummy data
    // char kamus1[][100] = {"bunga", "burung", "bumi"};
    // char kamus2[][100] = {"kucing", "anjing", "kelinci"};

    // awalanPanjang(kamus1, 3, hasil);
    // printf("Awalan terpanjang (dummy 1): \"%s\"\n", hasil);
    // awalanPanjang(kamus2, 3, hasil);
    // printf("Awalan terpanjang (dummy 2): \"%s\"\n", hasil);
