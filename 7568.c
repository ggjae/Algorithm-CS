#include <stdio.h>
int main(){
    int a[51][2];
    int b[51];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(int i=0;i<n;i++){
        int count = 1;
        for(int j=0;j<n;j++){
            if(a[i][0] < a[j][0] && a[i][1] < a[j][1]){
                count++;
            }
        }
        printf("%d ",count);
    }
    return 0;
}