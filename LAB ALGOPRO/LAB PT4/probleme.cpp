#include <stdio.h>
int main() {
	
	int T;
	scanf("%d", &T); getchar();
	int hasil[T];
	
	//input & process
	for(int i = 0; i < T; i++){
		int N;
		scanf("%d", &N);
		int A[N];
		
		for(int j = 0; j < N; j++){
			scanf("%d", &A[j]);
		}
		
		int jojoCount = 0;
		int liliCount = 0;
		
		for ( int k = 0; k < N; k++) {
            if (k % 2 == 0 && A[k] % 2 == 0) {  
                jojoCount++;
            }
            if (k % 2 != 0 && A[k] % 2 != 0) {  
                liliCount++;
            }
        }
        
        int jojoWins = (jojoCount % 2 == 0); 
        int liliWins = (liliCount % 2 != 0);  
        
        if(jojoWins && liliWins){
            hasil[i] = 0;
        } else if(jojoWins) {
            hasil[i] = 1;
        } else if(liliWins) {
            hasil[i] = -1;
        } else {
            hasil[i] = 0;
        }
	}
	
	// output
	for(int i = 0; i < T; i++){
    	printf("Case #%d: ", i + 1);
		if(hasil[i] == 1){
			printf(":)\n");
		} else if(hasil[i] == -1){
			printf(":(\n");
		} else{
			printf(":|\n");
		}
	}
	
	return 0;
}