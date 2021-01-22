#include <stdio.h>
#include <string.h>
int main(){
    int n;
    int count = 0;
	int num[10050];
	char s[8];
	scanf("%d",&n);
	for(int i = 666 ; i < 2700000 && count < n; i++){
		sprintf(s,"%d",i);
		if(strstr(s,"666")==NULL){
			continue;
		}
		else{
			num[count] = i;
			count++;
		}
	}
	printf("%d",num[n-1]);
	return 0;
}