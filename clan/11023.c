#include <stdio.h>
#include <string.h>
int main() {
	int a,sum;
    int n,c;
    sum = 0;
    while(scanf("%d",&a) != EOF){
        sum += a;
    }
    printf("%d",sum);
	return 0;
}