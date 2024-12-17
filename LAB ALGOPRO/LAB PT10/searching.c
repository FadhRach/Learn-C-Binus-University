#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j + 1]){ 
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int linearSearch(int arr[], int size, int data){
    for(int i = 0; i < size; i++){
        if(data == arr[i]){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int min, int max, int data){
    if(min <= max){
        int mid = min + (max - min) / 2;
        if(data == arr[mid]){
            return mid;
        } else if (data < arr[mid]){
            return binarySearch(arr, min, mid-1, data);
        } else if (data > arr[mid]){
            return binarySearch(arr, mid+1, max, data);
        } 
    }
    return -1;
}

int interpolationSearch(int arr[], int min, int max, int data){

}

int main() {
    int arr[] = {31, 14, 62, 82, 0, 64, 79, 32, 6, 83};
    int size = sizeof(arr)/sizeof(arr[0]);

    // Sorting
    bubbleSort(arr, size);

    // Print Array
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");


    //input
    int data;
    printf("input data: ");
    scanf("%d", &data); getchar();

    // Searching
    int index;
    // index = linearSearch(arr, size, data);
    index = binarySearch(arr, 0, size-1, data);

    if(index != -1){
        printf("%d ditemukan di index %d\n", data, index);
    } else{
        printf("%d tidak ditemukan :(\n", data);
    }


    return 0;
}