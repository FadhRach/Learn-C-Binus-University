#include <stdio.h>

int main() {
	
	int sizeBaris = 20;
	int sizeKolom = 20;
	
	int xPos = 10;
	int yPos = 10;
	
	char map[sizeBaris][sizeKolom];
	
	for(int i = 0; i < sizeBaris; i++){
		for(int j = 0; j < sizeKolom; j++){
			if (i == 0 || j == 0 || i == 19 || j == 19) {
				map[i][j] = '*';
			} else {
				map[i][j] = ' ';
			}
		}
	}
	
	char command;
	
	map[yPos][xPos] = 'O';
	
	while (true) {
		for (int i = 0; i < 32; i++){
			printf("\n");
		}
		for(int i = 0; i < sizeBaris; i++){
			for(int j = 0; j < sizeKolom; j++){
				printf("%c ", map[i][j]);
			}
			printf("\n");
		}
		
		printf("Input command [w|a|s|d]: ");
		scanf("%c", &command); getchar();
		
		switch(command) {
			case 'w': {
				map[yPos][xPos] = ' ';
				yPos--;
				map[yPos][xPos] = 'O';
				break;
			}
			case 'a': {
				map[yPos][xPos] = ' ';
				xPos--;
				map[yPos][xPos] = 'O';
				break;
			}
			case 's': {
				map[yPos][xPos] = ' ';
				yPos++;
				map[yPos][xPos] = 'O';
				break;
			}
			case 'd': {
				map[yPos][xPos] = ' ';
				xPos++;
				map[yPos][xPos] = 'O';
				break;
			}
		}

	}
	
	
	
	return 0;
}
