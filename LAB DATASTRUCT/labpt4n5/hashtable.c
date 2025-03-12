#include <stdio.h>
#define SIZE 10

int ht[SIZE];
// inisialisasi tabel hash dengan isian -1 belum ada isi
void initialize(){
    for(int i = 0; i < SIZE; i++){
        ht[i] = -1;
    }
}

//menyimpan nilai ke dalam hash table
void insert_val(){
    int val, key, index;
    printf("\nMasukan element yang ingin dimasukan: ");
    scanf("%d", &val);
    key = val % SIZE; //hash function modulus
    index = key;
    //Linear Probing jika terjadi collision
    while (ht[index] != -1){
        index = (index+1) % SIZE; //geser ke indeks berikut secara ...
        if(index == key){
            printf("Hash tablenya sudah penuh");
            return;
        }
    }
    ht[index] = val;
    printf("\n elemen yang dimasukan ada di index %d\n");
}

void display(){
    printf("\nHash Table: \n");
    for(int i = 0; i < SIZE; i++){
        printf("%d\t", ht[i]);
    }
    printf("\n");
}

void search_val(){
    int val, key, index;
    printf("\nMasukan element yang ingin dicari: ");
    scanf("%d", &val);
    key = val % SIZE; //hash function modulus
    index = key;
    //Linear probing sambil mencari nilai
    while(ht[index]!=-1){
        if(ht[index]=val){
            printf("\n elemen ditemukan di index %d\n");
            return;
        }
        index = (index+1) % SIZE;
        if(index == key) break; //jika loop ke awal maka ga ketemu
    }
    printf("\n Element tidak ditemukan\n");
}

void delete_val(){
    int val, key, index;
    printf("\nMasukan element yang ingin didelete: ");
    scanf("%d", &val);
    key = val % SIZE; //hash function modulus
    index = key;
    while(ht[index]!=-1){
        if(ht[index]=val){
            printf("\n elemen %d telah didelete\n");
            ht[index] = -1;
            return;
        }
        index = (index+1) % SIZE;
        if(index == key) break; //jika loop ke awal maka ga ketemu
    }
    printf("\n Element tidak ditemukan untuk didelete\n");
}

int main(){
    int option;
    initialize();
    do{
        printf("\nMenu\n 1.Insert\n 2.Search\n 3.Delete\n 4.Display\n 5.Exit\n Masukan input :");
        scanf("%d", &option);

        switch (option){
            case 1:
                insert_val();
                break;
            case 2:
                search_val();
                break;
            case 3:
                delete_val();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nKeluar dari program\n");
                break;
            default:
            printf("\nPilihan salah ulangi lagi\n");
                break;
        }
    } while(option !=5);
}