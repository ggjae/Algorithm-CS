#include <stdio.h>
int main() {
	int count = 0;
    int n,tmp,ans,tmp2;
    int bigtmp;
    scanf("%d",&n);
    tmp = n;
	while(1){
        tmp2 = (tmp%10) * 10;
        tmp2 = tmp2 + ((tmp/10) + (tmp%10))%10;
        tmp = tmp2;
        count++;
        if(tmp == n){
            break;
        }    
    }
    
	printf("%d",count);
	return 0;
}