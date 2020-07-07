#include <stdio.h>
int main(){
    int a[41][2];
    int n;
    scanf("%d",&n);
    a[0][0] = 1;
    a[0][1] = 0;
    a[1][0] = 0;
    a[1][1] = 1;

    for(int i=2;i<=40;i++){
        a[i][0] = a[i-1][0] + a[i-2][0];
        a[i][1] = a[i-1][1] + a[i-2][1];
    }
    int fibnum;
    for(int i=0;i<n;i++){
        scanf("%d",&fibnum);
        printf("%d %d\n",a[fibnum][0],a[fibnum][1]);
    }
    return 0;
}