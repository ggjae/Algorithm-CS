#include <stdio.h>
int check(int k){
    int count = 0;
    for(int i=1;i<=k;i++){
        int t = i;
        int n = i;
        while (n > 0) {
            t += n % 10;
            n /= 10;
        }
        if(t==k){
            return i;
        }
    }
    return 0;
}
int main(){
    int a;
    scanf("%d",&a);
    printf("%d\n",check(a));
    return 0;
}