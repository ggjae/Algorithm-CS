#include <stdio.h>
#include <string.h>
int main(){
    int n;
    int count = 0;
	int num[1001];
	char s[8];
	scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=1;i<n;i++){
        count = i;
        while(count>0 && num[count]<num[count-1]){
            int tmp = num[count];
            num[count] = num[count-1];
            num[count-1] = tmp;
            count--;
        }
    }
    for(int i= 0;i<n;i++){
        printf("%d\n",num[i]);
    }
	return 0;
}