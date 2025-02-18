#include <stdio.h>

void angka(int arr[], int n, int target) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Output: [%d, %d] pada indeks array [%d, %d]\n", arr[i], arr[j], i, j);
                return;
            }
        }
    }
    printf("Tidak ada penjumlahan angka yang cocok dengan target\n");
}

int main() {
    int size, target;
    
    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Masukkan elemen array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Masukkan target: ");
    scanf("%d", &target);
    
    angka(arr, size, target);
    
    return 0;
}