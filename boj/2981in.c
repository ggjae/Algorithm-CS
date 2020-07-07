#include <stdio.h>
#include <math.h>

int main(){
    int a[101];
    int n;
    int flag = 0;
    double max = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);    
        if(max < a[i]){
            max = a[i];
        }
    }
    for(int i=0;i<)
    for(int i=2;i<sqrt(max);i++){
        flag = 0;
        for(int j=1;j<n;j++){
            if(a[j] % i == a[j-1] % i){
                flag++;
            }
        }
        if(flag == n-1){
            printf("%d ",i);
        }
    }
}