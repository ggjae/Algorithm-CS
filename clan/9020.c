#include <stdio.h>
#include <math.h>
int main(){
    int n,a,min,max,flag;
    int prime[10001];
    prime[0] = 0;
    prime[1] = 0;
    scanf("%d",&n);
    int index = 0;
    for(int i=2;i<=10000;i++){
        flag = 0;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            prime[i] = 0;
        } else{
            prime[i] = 1;
        }
    }
    
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        for(int j=1;j<=a/2;j++){
            if(prime[j] == 1 && prime[a-j] == 1){
                max = a-j;
                min = j;
            }
        }
        printf("%d %d\n",min,max);
    }
    return 0;
}