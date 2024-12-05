#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int x, y;
} Point;

Point snake[WIDTH * HEIGHT];
int snake_length = 1;
Point apple;
char grid[HEIGHT][WIDTH];
int dx = 1, dy = 0;

void generateApple() {
    apple.x = rand() % WIDTH;
    apple.y = rand() % HEIGHT;
}

void initGame() {
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    snake_length = 1;
    generateApple();
}

void updateGrid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = ' ';
        };
    }
    grid[apple.y][apple.x] = 'O';
    for (int i = 0; i < snake_length; i++) {
        grid[snake[i].y][snake[i].x] = '*';
    }
}

void printGrid() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        printf("#");
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x]);
        }
        printf("#\n"); 
    }

    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
}

void moveSnake() {
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    snake[0].x += dx;
    snake[0].y += dy;

    if (snake[0].x == apple.x && snake[0].y == apple.y) {
        snake_length++;
        generateApple();
    }
    
    if (snake[0].x < 0 || snake[0].x >= WIDTH || snake[0].y < 0 || snake[0].y >= HEIGHT) {
        printf("Game Over!\n");
        exit(0);
    }

    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            printf("Game Over!\n");
            exit(0);
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

	do{
		
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
	
	puts("		[Menu]");
	puts("");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	puts("[1] Start Playing");
	puts("[2] Exit");
	puts("");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	puts("#LOVEASLAB<3");
	puts("");
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("=> ");
    scanf("%d", &choice);

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    switch(choice){
    	case 1:
    		srand(time(NULL));
    		initGame();

	    while (1) {
	        handleInput();
	        moveSnake(); 
	        updateGrid();
	        printGrid();
	        Sleep(200);
    	}

    		break;
    	case 2:
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

