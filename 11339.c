#include <stdio.h>
int main(){
    int n,k;
    int kind[11];
    int count = 0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&kind[i]);
    }
    while(k!=0){
        for(int i=n;i>0;){
            if(k-kind[i] >= 0){
                count++;
                k = k - kind[i];
            } else {
                i--;
            }
        }
    }
    printf("%d",count);
    return 0;
}