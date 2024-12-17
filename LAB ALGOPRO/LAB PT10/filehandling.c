#include <stdio.h>

void write(char names[100][100], int prices[], int count){
    // w = write
    // a = append
    FILE* f = fopen("menu.txt", "a");
    for(int i = 0; i < count; i++){
        fprintf(f, "%s#%d\n", names[i], prices[i]);
    }
    fclose(f);
}

void read(){
    // r = read
    char names[100];
    int price;
    FILE* f = fopen("menu.txt", "r");
    if(f == NULL){
        printf("File not exists!\n");
        return;
    }
    while(!feof(f)){
        fscanf(f, "%[^#]#%d\n", names, &price);
        printf("%s - %d\n", names, price);
    }
    fclose(f);
}

int main(){
    char names[100][100] = {{"Sushi Tei"},{"Okinawa Sushi"},{"Yugado"}};

    int prices[100] = {35000, 30000, 50000};

    // write(names, prices, 3);
    read();

    return 0;
}