#include <stdio.h>
int main(){
    int a[3];
    while(1){
        for(int i=0;i<3;i++){
            scanf("%d",&a[i]);
            
        }
        int b = a[0] * a[0];
        int c = a[1] * a[1];
        int d = a[2] * a[2];
        if(b == 0 && c == 0 && d == 0){
            return 0;
        }
        if(b+c == d || c+d == b || b+d == c){
            printf("right\n");
        } else{
            printf("wrong\n");
        }
    }
    
    return 0;
}