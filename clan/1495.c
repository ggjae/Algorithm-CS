#include <stdio.h>
int main(){
    int n,s,m;
    int sound[1001];
    int DP[1001][2] = {0, };
    scanf("%d %d %d",&n,&s,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&sound[i]);
    }
    DP[s][0] = 1;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(DP[j][0] != 0){
                if(j - sound[i] >= 0){
                    DP[j - sound[i]][1] = 1;
                } if(j + sound[i] <= m){
                    DP[j + sound[i]][1] = 1;
                }
            }
        }
        for(int j=0;j<=m;++j){
            DP[j][0] = DP[j][1];
            DP[j][1] = 0;
        }
    }
    for(int i=m;i>=0;--i){
        if(DP[i][0] == 1){
            printf("%d",i);
            return 0;
        } if(i == 0){
            printf("-1");
            return 0;
        }
    }
    return 0;
}