#include <stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    for(int i=1;i<=a;i++){
        for(int k=1;k<=a;k++){
            for(int j=1;j<=b;j++){
                printf("%d %d",i,k);
            }
        }
        printf("\n");
        
    }
    return 0;
}