#include <stdio.h>
#include <stdlib.h>
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        for(int j=a-1;j>=0;j--){
            if(j>i){
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}