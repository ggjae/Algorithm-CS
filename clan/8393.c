#include <stdio.h>
#include <string.h>
int main() {
	int a,b,sum;
    int n,c;
    sum = 0;
    scanf("%d",&a);
    for(int i=0;i<=a;i++){
        sum += i;
    }
    printf("%d",sum);
	return 0;
}