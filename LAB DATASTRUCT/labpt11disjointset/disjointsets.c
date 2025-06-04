#include <stdio.h>

#define N 10

int parent[N];
int rank[N];

void makeSet(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x){
    if(parent[x] != x)
        parent[x] = find(parent[x]); // Path compression
    return parent[x];
}

void unionSets(int x, int y){
    int xRoot = find(x);
    int yRoot = find(y);

    if(xRoot == yRoot) return;

    // Union by rank
    if(rank[xRoot] < rank[yRoot]){
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]){
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

void printParent(){
    printf("index:  ");
    for(int i = 0; i < N; i++) printf("%d ", i);
    printf("\nparent: ");
    for(int i = 0; i < N; i++) printf("%d ", parent[i]);
    printf("\nrank:   ");
    for(int i = 0; i < N; i++) printf("%d ", rank[i]);
    printf("\n\n");
}

int main(){
    makeSet(N);

    // Contoh union
    unionSets(0, 1);
    unionSets(1, 2);
    unionSets(3, 4);
    unionSets(2, 4); // gabung 0-1-2 sama 3-4

    printParent();

    // Cek find
    printf("find(4): %d\n", find(4));
    printf("find(0): %d\n", find(0));

    printParent(); // Lihat hasil path compression

    return 0;
}
