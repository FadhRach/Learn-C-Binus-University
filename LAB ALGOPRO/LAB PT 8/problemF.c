// #include <stdio.h>

// void tuker(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void permutasi(int arr[], int start, int end){
//     if(start == end){
//         for(int i = 0; i < end; i++){
//             printf("%d", arr[i]);
//         }
//         printf("\n");
//         return;
//     }

//     for(int i = start; i < end; i++){
//         tuker(&arr[start], &arr[i]);

//         permutasi(arr, start + 1, end);

//         tuker(&arr[start], &arr[i]);

//     }
// }

// int main(){

//     int N;
//     scanf("%d", &N);

//     int arr[N];

//     for(int i = 0; i < N; i++){
//         scanf("%d", &arr[i]);
//     }

//     for (int i = 0; i < N - 1; i++) {
//         for (int j = i + 1; j < N; j++) {
//             if (arr[i] > arr[j]) {
//                 tuker(&arr[i], &arr[j]);
//             }
//         }
//     }

//     permutasi(arr, 0, N);

//     return 0;
// }

#include <stdio.h>

int main() {
    int n, arr[6], i, j, k, temp;
    int faktorial = 1;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        faktorial *= (i + 1);
    }

    int posisi[6] = {0};

    for (i = 0; i < faktorial; i++) {
        for (j = 0; j < n; j++) {
            printf("%d", arr[j]);
        }
        printf("\n");
        for (j = n - 2; j >= 0 && arr[j] >= arr[j + 1]; j--);

        if (j < 0) break;

        for (k = n - 1; arr[k] <= arr[j]; k--);


        temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;


        for (k = j + 1, j = n - 1; k < j; k++, j--) {
            temp = arr[k];
            arr[k] = arr[j];
            arr[j] = temp;
        }
    }

    return 0;
}