#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int sum=0;
    int n;
    char str[5];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",str);
        for(int j=0;j<strlen(str);j++){
            if(str[j] > '0' && str[j] <= '9'){
                sum += str[j] - '0';
            }
        }
        printf("%d\n",sum);
        sum = 0;
    }
    
	return 0;
}