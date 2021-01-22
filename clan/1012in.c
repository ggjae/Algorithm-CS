#include <stdio.h>
int main(){
    int a[50][50];
    int check[50][50];
    int T,M,N,K;
    int x,y;
    int jirungi = 0;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d %d",&M,&N,&K);
        for(int j=0;j<K;j++){
            scanf("%d %d",&x,&y);
            a[x][y] = 1;
        }
        for(int j=0;j<M;j++){
            for (int l=0;l<N;l++){
                
            }
        }
    }
}