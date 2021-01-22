#include <stdio.h>
int gcd(int a, int b){
    int tmp;
    if(a>b){
        ;
    } else {
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b != 0){ // a>b를 내가 가정해놓은 상태
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b){
    if(gcd(a,b)!=1){
        return gcd(a,b)*((a/gcd(a,b))*(b/gcd(a,b)));
    } else {
        return a*b;
    }
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",gcd(a,b));
    printf("%d\n",lcm(a,b));
    return 0;
}