#include <stdio.h>
char a[1000000];
int main(){
    long long int a[10001];
    int n;
    scanf("%d",&n);
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;

    for(int i=2;i<=10000;i++){
        a[i] = a[i-1] + a[i-2];
    }
    printf("%lld",a[n]);
    return 0;
}