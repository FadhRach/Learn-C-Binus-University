#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    char S[1000];
    char hasil[T];
    
    for(int i = 1; i <= T; i++){
		scanf("%s", S);
		
		int x = strlen(S);
		int p = 1;
		for(int j = 0; j < x / 2; j++){
			if(S[j] != S[x - j - 1]){
				p = 0;
				break;
			}
		}
		if(p){
			printf("Case #%d: yes\n", i);
		} else {
			printf("Case #%d: no\n", i);
		}
	}
	
	return 0;
}
    
    
    
// PERCOBAAN KEDUA WRONGANSWER 40  
    
//    for(int i = 0; i < T; i++) {
//        scanf(" %[^\n]", S);
//        int len = strlen(S);
//        
//        if (len <= 1 || S[0] == S[len - 1]) {
//            hasil[i] = 1;
//        } else {
//            hasil[i] = 0;
//        }
//    }
//    
//    
//    for(int i = 0; i < T; i++) {
//        if (hasil[i] == 1) {
//            printf("Case #%d: yes\n", i + 1);
//        } else {
//            printf("Case #%d: no\n", i + 1);
//        }
//    }
    
    
    
// PERCOBAAN PERTAMA WRONGANSWER 40
    
//    for(int i = 0; i < T; i++){
//		scanf(" %[^\n]", S);
//		int len = strlen(S);
//		
//		char hurufAwal = S[0];
//		char hurufAkhir = S[len-1];
//		if(hurufAwal == hurufAkhir){
//			hasil[i] = 1;
//		} else {
//			hasil[i] = 0;
//		}
//	}
//	
//	for(int i = 0; i < T; i++) {
//		if (hasil[i] == 1) {
//			printf("Case #%d: yes\n", i+1);
//		} else {
//			printf("Case #%d: no\n", i+1);
//		}
//	}
    
