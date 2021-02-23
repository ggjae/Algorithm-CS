#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,cnt;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        if(m==1) d++;
        if(m==2||d==4){
            if(c&&b&&a) cnt++,c=0;
            if(b&&a) c=1,b=0;
            if(a) b=1;
            a=1; d=0;
        }
        if(m==3){
            if(c) cnt++,c=0;
            if(b) c=1,b=0;
            if(a) b=1,a=0;
            d++;
            if(d==4) d=0,a=1;
        }
    }
    printf("%d",cnt);
}