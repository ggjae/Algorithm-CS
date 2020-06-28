#include <stdio.h>
#include <string.h>
int main() {
	char a[101];
    int acount[26];
    memset(acount,-1,sizeof(acount));
    int max = 0;
    int tmp,flag;
    scanf("%s",&a);
    for(int i=0;i<strlen(a);i++){
		tmp = (int)a[i];
        if(acount[tmp-97] == -1){
            acount[tmp - 97] = i;
        } 
    }
    for(int i =0;i<26;i++){
        printf("%d ",acount[i]);
    }
    return 0;
}