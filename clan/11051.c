#include <stdio.h>
int arr[1001][1001];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    for(int i=2;i<=n;i++){
        arr[i][0] = 1;
        for(int j=1;j<i+1;j++){
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % 10007; 
        }
        arr[i][i] = 1;
    }
    printf("%d",arr[n][k]);
}