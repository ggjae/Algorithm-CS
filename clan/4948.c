#include <stdio.h>
#include <math.h>
int main(){
    int n,count;
    while(1){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        count = 0;
        for(int i=n+1;i<=2*n;i++){
            for(int j=2;j<=sqrt(i);j++){
                if(i%j == 0){
                    count++;
                    break;
                }
            }
        }
        printf("%d\n",n-count);
    }
    
    return 0;
}