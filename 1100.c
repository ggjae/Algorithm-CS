#include <stdio.h>
int main() {
	char sum[8][8];
	int sumc = 0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			scanf("%c",&sum[i][j]);
			if(sum[i][j] == 'F' && i%2 == 1 && j%2 == 1){
				sumc++;
			} else if (sum[i][j] == 'F' && i%2 == 0 && j%2 == 0){
				sumc++;
			}
		}
        getchar();
	}
    
	printf("%d",sumc);
	return 0;
}