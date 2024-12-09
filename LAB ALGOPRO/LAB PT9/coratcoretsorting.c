#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort
void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j + 1]){ // < : Descending, > : Ascending
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// selection sort
void selectionSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){ // < : Descending, > : Ascending
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Insertion sort
void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp){ // < : Descending, > : Ascending
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main(){
    int arr[] = {15, 28, 10, 65, 12, 13, 62, 84, 24, 21};
    // kalau sorting secara alphabet pake string compare
    int size = sizeof(arr)/ sizeof(arr[0]);

    printf("Before sorting : ");
    for( int i = 0; i < size; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
    
    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    insertionSort(arr, size);

    printf("After sorting : ");
    for( int i = 0; i < size; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}