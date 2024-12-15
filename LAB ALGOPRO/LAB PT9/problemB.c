#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    scanf("%s", password);

    int panjang = strlen(password);

    if (panjang < 8 || panjang > 33) {
        printf("invalid password\n");
        return 0;
    }

    int digitPass = 0, UpperPass = 0, SpecialCharPass = 0;
    char specialChar[] = "!@#$%^&*()-+";

    for (int i = 0; i < panjang; i++) {
        if (isdigit(password[i])) digitPass = 1;
        else if (isupper(password[i])) UpperPass = 1;
        else if (strchr(specialChar, password[i])) SpecialCharPass = 1;
    }

    int criteria = digitPass + UpperPass + SpecialCharPass;

    if (criteria < 2) {
        printf("weak password\n");
    } else if (criteria == 2) {
        printf("medium password\n");
    } else if (criteria == 3) {
        printf("strong password\n");
    }

    return 0;
}
