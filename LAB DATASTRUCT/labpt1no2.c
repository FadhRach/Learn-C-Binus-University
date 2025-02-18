#include <stdio.h>

int maxProfit(int harga_saham[], int ukuran) {
    if (ukuran == 0) return 0;

    int min_harga = harga_saham[0];
    int max_profit = 0;

    for (int i = 1; i < ukuran; i++) {
        if (harga_saham[i] < min_harga) {
            min_harga = harga_saham[i];
        } else {
            int profit = harga_saham[i] - min_harga;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
    }

    return max_profit;
}

int main() {
    int ukuran;

    printf("Masukkan jumlah saham: ");
    scanf("%d", &ukuran);

    if (ukuran <= 0) {
        printf("Jumlah harga saham harus lebih dari 0.\n");
        return 1;
    }

    int harga_saham[ukuran];

    printf("Masukkan harga saham:\n");
    for (int i = 0; i < ukuran; i++) {
        scanf("%d", &harga_saham[i]);
    }

    printf("Profit maksimum: %d\n", maxProfit(harga_saham, ukuran));

    return 0;
}