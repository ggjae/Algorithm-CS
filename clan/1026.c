#include <stdio.h>
int main() {
	int A[50][2]={0,};
	int B[50][2]={0,};
    int C[50];
	int n,tmpmin,tmpmax,sum;
    int min = 101;
    int mintmp;
    int max = -1;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&A[i][0]);
    }
    for(int i =0;i<n;i++){
        scanf("%d",&B[i][0]);
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(min>A[i][0] && A[i][1] == 0){
                min = A[i][0];
                tmpmin = i;
            }
            if(max<B[i][0] && B[i][1] == 0){
                max = B[i][0];
                tmpmax = i;
            }
        }
        C[tmpmax] = min;
        A[tmpmin][1] = 1;
        B[tmpmax][1] = 1;
        min = 101;
        max = -1;
    }
    for(int i =0;i<n;i++){
        int z = B[i][0] * C[i];
        sum = sum + z;
    }
    printf("%d",sum);
	return 0;
}