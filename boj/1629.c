#include <stdio.h>
long long multi(int a,int b,int c){
    if (b == 0){
        return 1;
    } else if (b%2 == 0){
        long long n = multi(a,b/2, c);
        return (n*n) % c;
    } else {
        long long n = multi(a, (b-1) / 2, c);
        return ((a * n) %c * n) % c;
    }
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%lld",multi(a,b,c));
}