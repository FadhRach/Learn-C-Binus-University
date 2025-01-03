#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[51];
    int urgensi;
} Pasien;

void bubbleSort(Pasien arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j].urgensi < arr[j + 1].urgensi || 
               (arr[j].urgensi == arr[j + 1].urgensi && 
               strcmp(arr[j].nama, arr[j + 1].nama) > 0)) {
                Pasien temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Pasien pasien[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d", pasien[i].nama, &pasien[i].urgensi);
    }

    // Sorting
    bubbleSort(pasien, N);

    for (int i = 0; i < N; i++) {
        printf("%s %d\n", pasien[i].nama, pasien[i].urgensi);
    }

    return 0;
}
