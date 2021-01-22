#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b;
    int c[10001];
    scanf("%d %d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d",&c[i]);
        if(c[i] < b){
            printf("%d ",c[i]);
        } else {
            ;
        }
    }
    return 0;
}