#include <stdio.h>
#include <string.h>
int main() {
	int value[10] = {0,};
    int remind[10];
    int sum,t;
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    sum = a*b*c;
    while(sum > 0){
        t = sum%10;
        sum = sum/10;
        value[t]++;
    }
    for(int i=0;i<10;i++){
        printf("%d\n",value[i]);
    }
    return 0;
}