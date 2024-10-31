#include <stdio.h>

int main() {
    int testCase, testCaseCount;
    scanf("%d", &testCase);

    for(testCaseCount = 0; testCaseCount < testCase; testCaseCount++) {
        int size;
        scanf("%d", &size);

        int matrix1[50][50], matrix2[50][50], matrix3[50][50];
        int result[50][50] = {0}, finalResult[50][50] = {0};
        int i, j, k;

        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                scanf("%d", &matrix1[i][j]);
            }
        }

        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                scanf("%d", &matrix2[i][j]);
            }
        }

        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                scanf("%d", &matrix3[i][j]);
            }
        }

        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                for(k = 0; k < size; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                for(k = 0; k < size; k++) {
                    finalResult[i][j] += result[i][k] * matrix3[k][j];
                }
            }
        }

        //output
        printf("Case #%d:\n", testCaseCount + 1);
        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                if (j > 0) printf(" ");
                printf("%d", finalResult[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
