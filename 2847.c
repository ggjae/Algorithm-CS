#include <stdio.h>
int main(){
    int flag = 1;
    int n;
    int count = 0;
    int sumb = 0;
    int a[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n-1;i>0;i--){
        if(a[i]<=a[i-1]){
            count = 0;
            count = a[i-1] - a[i] + 1;
            a[i-1] = a[i-1] - count;
        }
        
    }
    printf("%d",sumb);

    return 0;
}