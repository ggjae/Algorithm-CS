#include <stdio.h>
int main(){
    int a[9];
    int max = -1;
    int tmp = 0;
    for(int i=0;i<9;i++){
        scanf("%d",&a[i]);
        if(max < a[i]){
            max = a[i];
            tmp = i;
        }
    }
    printf("%d\n",max);
    printf("%d",tmp+1);
}