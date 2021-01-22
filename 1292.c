#include <stdio.h>
int main(){
    int c[2000];
    int a,b;
    int ans = 0;
    int i = 0;
    int n = 1;
    scanf("%d %d",&a,&b);
    
    while(i<=1000){
        for(int j=1;j<=n;j++){
            c[i] = n;
            i++; // 문제 일어날 수 있습니다. 희재님.
        }
        n++;
    }
    while(a != b){
        ans += c[a-1];
        a++;
    }
    if(a==b){
       ans += c[a-1];
    }
    printf("%d",ans);
    return 0;
}