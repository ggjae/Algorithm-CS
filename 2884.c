#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a == 0 && b < 45){
        printf("23 %d",60-abs(45-b));
    } 
    else if(b<45){
        printf("%d %d",a-1,60-abs(45-b));
    } else{
        printf("%d %d",a,b-45);
    }
    return 0;
}