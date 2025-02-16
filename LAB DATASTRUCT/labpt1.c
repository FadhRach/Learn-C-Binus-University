#include <stdio.h>

void swap(int *x, int *y){
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j + 1]){ // < : Descending, > : Ascending
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
    // int a, b;
    // printf("Masukan nilai a : ");
    // scanf("%d", &a);
    // printf("Masukan nilai b : ");
    // scanf("%d", &b);
    // printf("Nilai sebelum ditukar  a=%d dan b=%d \n", a, b);
    // swap(&a, &b);
    // printf("Nilai sesudah ditukar  a=%d dan b=%d \n", a, b);


    int arr[20];
    int n, terkecil;
    float total, ratarata;

    terkecil = arr[0];

    printf("Masukan jumlah elemen pada array : ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        printf("Masukan arr[%d] :", i);
        scanf("%d", &arr[i]);
        total += arr[i];
        if(arr[i] < terkecil){
            terkecil = arr[i];
        }
    }

    ratarata = total / n;

    printf("elemen didalam array antara lain \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nRata-rata elemen dalam array: %.2f\n", ratarata);
    printf("\nTerkecil elemen dalam array: %d\n", terkecil);

    bubbleSort(arr, n);
    printf("dah sorting array \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    swap(&arr[1], &arr[n-2]);
    printf("dah tuker index 2 kecil dan 2 besar array \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    
}