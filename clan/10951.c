#include <stdio.h>
#include <string.h>
int main() {
	int a,b;
    int n,c;
    while(1){
        if(scanf("%d %d",&a,&b) != -1){
            printf("%d\n",a+b);
        } else {
            break;
        }
        
    }
	return 0;
}