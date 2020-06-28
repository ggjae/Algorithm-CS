#include <stdio.h>
#include <math.h>
int main(){
    int count,n,flag;
    int a[101];
    count = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        flag = 0;
        if(a[i] != 1){
            for(int j=2;j<=sqrt(a[i]);j++){
                if(a[i]%j == 0){
                    flag = 1;
                } else {
                    continue;
                }
            }
        } else {
            flag = 1;
        }
    
        if(flag == 0){
            count++;
        } else {
            continue;
        }
    }
    printf("%d",count);
    return 0;
}