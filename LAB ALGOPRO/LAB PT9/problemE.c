#include <stdio.h>
#include <string.h>

typedef struct {
    char names[200][11];
    int count;          
} Group;

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);

        Group groups[21] = {0};

        for (int i = 0; i < N; i++) {
            char name[11];
            int groupNum;
            scanf("%s %d", name, &groupNum);

            strcpy(groups[groupNum].names[groups[groupNum].count], name);
            groups[groupNum].count++;
        }

        printf("Case #%d:\n", t + 1);

        for (int i = 1; i <= 20; i++) {
            if (groups[i].count > 0) {
                printf("Group %d(%d):\n", i, groups[i].count);
                for (int j = 0; j < groups[i].count; j++) {
                    printf("%s\n", groups[i].names[j]);
                }
            }
        }
    }

    return 0;
}
