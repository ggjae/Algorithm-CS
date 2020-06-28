#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char a[2002][8];
    char tmp[2002][8];
    int n,b,tmpval;
    int count = 0;
    scanf("%d",&n);
    b = 2*n;
    for(int i=0;i<2*n;i++){
        scanf("%s",&a[i]);
    }
    for(int i=0;i<2*n;i++){
        if(a[i] != a[n+i]){
            tmp[i] = a[i];
            tmpval = i;
            
        }
    }
    return 0;
}