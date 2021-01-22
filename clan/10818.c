#include <stdio.h>
int a[1000001];
int main(){
    int N;
    int max = -1000001;
    int min = 1000001;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        if(max < a[i]){
            max = a[i];
        } if(min > a[i]){
            min = a[i];
        }
    }
    printf("%d ",min);
    printf("%d",max);
    return 0;
}