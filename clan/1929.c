#include <stdio.h>
#include <math.h>
int a[1000001];
int main(){
    int b,c;
    int flag = 0;
    for(int i=0;i<1000001;i++){
        a[i] = i;
    }
    scanf("%d %d",&b,&c);
    for(int i=b;i<=c;i++){
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag = 1;
                break;
            }
        }
        if(flag != 1 && i != 1){
            printf("%d\n",i);
        }
        flag = 0;
    }
    return 0;
}