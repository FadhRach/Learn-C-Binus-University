#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 15
#define MAX_PLAYERS 100

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// STRUCT ----------------------------------------------
typedef struct {
    char name[50];
    int score;
} Player;

typedef struct {
    int x, y;
} Point;

// GLOBAL VARIABLE -------------------------------------
Point snake[WIDTH * HEIGHT];
int snake_length = 1;
Point apple;
char grid[HEIGHT][WIDTH];
int dx = 1, dy = 0;
int score = 0;
char playerName[50];
Player players[MAX_PLAYERS];
int playerCount = 0;

void generateApple() {
    int valid = 0;
    while (!valid) {
        apple.x = rand() % WIDTH;
        apple.y = rand() % HEIGHT;

        valid = 1;
        for (int i = 0; i < snake_length; i++) {
            if (snake[i].x == apple.x && snake[i].y == apple.y) {
                valid = 0;
                break;
            }
        }
    }
}

void initGame() {
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    snake_length = 1;
    score = 0;
    generateApple();
}

void updateGrid() {
    // Membersihkan grid
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = ' '; // Set kosong
        }
    }

    // Menempatkan apel
    grid[apple.y][apple.x] = 'O';

    // Menempatkan ular
    for (int i = 0; i < snake_length; i++) {
        grid[snake[i].y][snake[i].x] = '*';
    }
}

void printGrid() {
    system("cls");

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Player: %s | Score: %d\n", playerName, score);

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("#");
        for (int x = 0; x < WIDTH; x++) {
            if (grid[y][x] == 'O') {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("%c", grid[y][x]);
            } else if (grid[y][x] == '*') {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("%c", grid[y][x]);
            } else {
                printf(" ");
            }
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("#\n");
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void saveScore() {
    FILE *file = fopen("scoreboard.txt", "a");
    if (file == NULL) {
        printf("Error: Could not open scoreboard file.\n");
        return;
    }
    fprintf(file, "%s: %d\n", playerName, score);
    fclose(file);
}

void loadScores() {
    FILE *file = fopen("scoreboard.txt", "r");
    if (file == NULL) {
        printf("No scoreboard available.\n");
        return;
    }

    playerCount = 0;
    while (fscanf(file, "%[^:]: %d\n", players[playerCount].name, &players[playerCount].score) != EOF) {
        playerCount++;
    }
    fclose(file);
}

void bubbleSortScores() {
    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = 0; j < playerCount - i - 1; j++) {
            if (players[j].score < players[j + 1].score || 
               (players[j].score == players[j + 1].score && strcmp(players[j].name, players[j + 1].name) > 0)) {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}

void displayScoreboard() {
    loadScores();
    bubbleSortScores();

    system("cls");
    printf("\n===== SCOREBOARD =====\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("======================\n");

    printf("Press Enter to return to the Main Menu...");
    getchar(); getchar();
}

void searchPlayer() {
    char searchName[50];
    int found = 0;

    system("cls");
    printf("\nEnter player name to search: ");
    getchar(); // Clear input buffer
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    printf("\n===== SEARCH RESULT =====\n");
    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, searchName) == 0) {
            printf("%s: %d\n", players[i].name, players[i].score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Player not found.\n");
    }
    printf("=========================\n");
    printf("Press Enter to return to the Main Menu...");
    getchar();
}

void moveSnake() {
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    snake[0].x += dx;
    snake[0].y += dy;

    if (snake[0].x == apple.x && snake[0].y == apple.y) {
        snake_length++;
        score += 10;
        generateApple();
    }

    if (snake[0].x < 0 || snake[0].x >= WIDTH || snake[0].y < 0 || snake[0].y >= HEIGHT) {
        system("cls");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("\nGame Over! Your Score: %d\n", score);
        saveScore();
        printf("Press Enter to return to the Main Menu...");
        getchar(); getchar();
        snake_length = 0;
        return;
    }

    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            system("cls");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\nGame Over! Your Score: %d\n", score);
            saveScore();
            printf("Press Enter to return to the Main Menu...");
            getchar(); getchar();
            snake_length = 0;
            return;
        }
    }
}

void handleInput() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'w':
                if (dy == 0) { dx = 0; dy = -1; }
                break;
            case 's':
                if (dy == 0) { dx = 0; dy = 1; }
                break;
            case 'a':
                if (dx == 0) { dx = -1; dy = 0; }
                break;
            case 'd':
                if (dx == 0) { dx = 1; dy = 0; }
                break;
        }
    }
}

int main() {
    int choice;
    int run = 1;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    printf("Enter your name: ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = '\0';

    do {
        system("cls");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

        puts("    ______      _______       __       ");
        puts("   / ____/___ _/ ____(_)___  / /_____ _");
        puts("  / /   / __ `/ /   / / __ \\/ __/ __ `/");
        puts(" / /___/ /_/ / /___/ / / / / /_/ /_/ / ");
        puts(" \\____/\\__,_/\\____/_/_/ /_/\\__/\\__,_/  ");
        puts("                                       ");

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        puts("");
        puts("[?] Made by : Kelompok Kami");
        puts("[!] Don't Change The Copyright & Author !!!");
        puts("[<\\>] This game called Cacing Cinta <3");
        puts("");

        puts("        [Menu]");
        puts("");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        puts("[1] Start Playing");
        puts("[2] Leaderboard");
        puts("[3] Search Player");
        puts("[4] Exit");
        puts("");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        puts("#LOVEASLAB<3");
        puts("");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        printf("=> ");
        scanf("%d", &choice);

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        switch (choice) {
            case 1:
                srand(time(NULL));
                initGame();

                while (1) {
                    handleInput();
                    moveSnake();
                    if (snake_length == 0) {  // Ketika game over, keluar dari loop
                        break;
                    }
                    updateGrid();
                    printGrid();
                    Sleep(200);
                }
                break;
            case 2:
                displayScoreboard();
                break;
            case 3:
                searchPlayer();
                break;
            case 4:
                system("cls");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                Sleep(1000);
                printf("Exitting.");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(2000);
                printf("Successfully Exit");
                system("cls");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                run = 0;
                break;
        }
    } while (run);

    return 0;
}
