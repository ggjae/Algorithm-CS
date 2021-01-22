#include <stdio.h>
long long int ans[10];
void cal(int n){
    while(n>0){
        ans[n%10] += 1;
        n = n/10;
    }
}
int main(){
    int a;
    scanf("%d",&a);
    // 1부터 10까지 구해보고, 123456789 까지 가겠지?
    // 10 부터 시작할땐? 10, 11 12 13 14 15 16 17 18 19 까지 가겠지.
    cal(a);

    for(int i=0;i<)
    return 0;
}