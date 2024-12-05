#include <stdio.h>
#include <string.h>

int main () {  
    int X, Y, T, a, b, c;
    scanf("%d %d", &X, &Y);
    int arr[X][Y];
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &a, &b, &c);
        arr[a - 1][b - 1] = c;
    }
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            printf("%d", arr[i][j]);
            if (j < Y - 1){
            	printf(" ");
			}
        }
        printf("\n");
    }
return 0;
}