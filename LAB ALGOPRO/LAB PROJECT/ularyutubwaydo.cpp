#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char map[10][20];
char player = '^'; //head snake
char tail = '*';
char food = '$';
int xFood, yFood;
int y=5, x=5;
int xTail[10];
int yTail[10];
int width=20, height=10;
int nTail = 2;
int maxTail = 1000000;
int score;

void generateMap(){
	for(int i=0; i<10; i++){
		for(int j=0; j<20; j++){
			if(i == 0 || i == 9){
				map[i][j] = '#';
			}else if(j == 0 || j == 19){
				map[i][j] = '#';
			}else{
				map[i][j] = ' ';
			}
		}
	}
	map[y][x] = player;
	map[yFood][xFood] = food;
	for(int i = 0; i<=nTail; i++){
		map[yTail[i]][xTail[i]] = tail;
	}
}

void displayMap(){
	for(int i=0; i<10; i++){
		for(int j=0; j<20; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("Score : %d\n", score);
}

int main(){
	time_t t;
	score = 0;
	char move;
	srand((unsigned) time_t(&t));
	xFood = rand() % 18+1;
	yFood = rand() % 8+1;
	system("color 2");
	yTail[0] = y+1;
	xTail[0] = x;
	yTail[1] = y+2;
	xTail[1] = x;
	
	do{
		system("cls");
		generateMap();
		displayMap();
		move = getch();
		
		switch(move){
			case 'w':
				player = '^';
				if(y-1 > 0){
					yTail[0] = y; xTail[0] = x;
					y--;
				}
				break;
			case 'a':
				player = '<';
				if(x-1 > 0){
					yTail[0] = y; xTail[0] = x;
					x--;
				}
				break;
			case 's':
				player = 'v';
				if(y+1 < height-1){
					yTail[0] = y; xTail[0] = x;
					y++;
				}
				break;
			case 'd':
				player = '>';
				if(x+1 < width-1){
					yTail[0] = y; xTail[0] = x;
					x++;
				}
				break;
		}
		if(y == yFood && x == xFood){
			map[y][x] = player;
			score++;
			if(nTail < 10){
				nTail++;
			}
			xFood = rand() % 18+1;
			yFood = rand() % 8+1;
		}
		
		for(int i = 9; i>0; i--){
			yTail[i] = yTail[i-1];
			xTail[i] = xTail[i-1];
		}
	} while(score < 10);
	printf("CONGRATULATIONS\n");
	printf("your score is : %d\n", score);
	
	
	
	return 0;
}

