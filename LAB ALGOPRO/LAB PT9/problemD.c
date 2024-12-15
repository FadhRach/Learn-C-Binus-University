#include <stdio.h>

typedef struct {
    char id[11];
    char name[16];
    int score;
} Student;

int main() {
    int N;
    scanf("%d", &N);

    Student students[50000];
    int totalScore = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", students[i].id); getchar();
        scanf("%[^\n]", students[i].name); getchar();
        scanf("%d", &students[i].score); getchar();
        totalScore += students[i].score;
    }

    double mean = (double)totalScore / N;

    for (int i = 0; i < N; i++) {
        if (students[i].score >= mean) {
            printf("%s %s\n", students[i].id, students[i].name);
        }
    }

    return 0;
}
