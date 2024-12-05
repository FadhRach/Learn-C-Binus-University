#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define LEBAR 20
#define TINGGI 10

typedef struct {
    int x;
    int y;
} Posisi;

Posisi ular[100]; // Maksimal panjang ular
int panjang_ular = 1;
Posisi makanan;
char arah = 'd'; // Awal bergerak ke kanan

void tampilkan_peta() {
    system("cls");
    char peta[TINGGI][LEBAR];

    // Inisialisasi peta kosong
    for (int i = 0; i < TINGGI; i++) {
        for (int j = 0; j < LEBAR; j++) {
            peta[i][j] = ' ';
        }
    }

    // Tambahkan dinding
    for (int i = 0; i < LEBAR; i++) {
        peta[0][i] = '#';
        peta[TINGGI - 1][i] = '#';
    }
    for (int i = 0; i < TINGGI; i++) {
        peta[i][0] = '#';
        peta[i][LEBAR - 1] = '#';
    }

    // Tambahkan ular
    for (int i = 0; i < panjang_ular; i++) {
        peta[ular[i].y][ular[i].x] = 'O';
    }

    // Tambahkan makanan
    peta[makanan.y][makanan.x] = '*';

    // Cetak peta
    for (int i = 0; i < TINGGI; i++) {
        for (int j = 0; j < LEBAR; j++) {
            printf("%c", peta[i][j]);
        }
        printf("\n");
    }
}

void buat_makanan() {
    makanan.x = rand() % (LEBAR - 2) + 1;
    makanan.y = rand() % (TINGGI - 2) + 1;
}

void gerakkan_ular() {
    // Perbarui posisi tubuh ular
    for (int i = panjang_ular - 1; i > 0; i--) {
        ular[i] = ular[i - 1];
    }

    // Gerakkan kepala ular
    switch (arah) {
        case 'w': ular[0].y--; break; // Atas
        case 's': ular[0].y++; break; // Bawah
        case 'a': ular[0].x--; break; // Kiri
        case 'd': ular[0].x++; break; // Kanan
    }
}

int cek_tabrakan() {
    // Cek tabrakan dengan dinding
    if (ular[0].x == 0 || ular[0].x == LEBAR - 1 ||
        ular[0].y == 0 || ular[0].y == TINGGI - 1) {
        return 1;
    }

    // Cek tabrakan dengan tubuh sendiri
    for (int i = 1; i < panjang_ular; i++) {
        if (ular[0].x == ular[i].x && ular[0].y == ular[i].y) {
            return 1;
        }
    }

    return 0;
}

void periksa_makanan() {
    if (ular[0].x == makanan.x && ular[0].y == makanan.y) {
        panjang_ular++;
        buat_makanan();
    }
}

int main() {
    srand(time(0));

    // Inisialisasi posisi awal ular
    ular[0].x = LEBAR / 2;
    ular[0].y = TINGGI / 2;

    buat_makanan();

    while (1) {
        tampilkan_peta();

        // Input pemain
        if (_kbhit()) {
            char input = _getch();
            if ((input == 'w' || input == 's' || input == 'a' || input == 'd') &&
                (abs(input - arah) != 2)) { // Hindari arah berlawanan
                arah = input;
            }
        }

        gerakkan_ular();
        if (cek_tabrakan()) {
            printf("Game Over! Skor: %d\n", panjang_ular - 1);
            break;
        }
        periksa_makanan();

        Sleep(500); // Kecepatan permainan
    }

    return 0;
}
