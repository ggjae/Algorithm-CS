#include <stdio.h>
#include <string.h>
int main() {
	char a[1000001];
    int acount[26] = {0,};
    int max = 0;
    int tmp,flag;
    scanf("%s",&a);
    for(int i=0;i<strlen(a);i++){
        if (a[i] > 64 && a[i] < 91) { //대문자일 경우
			tmp = (int)a[i];
			acount[tmp - 65]++;
		}
		else if (a[i] > 96 && a[i] < 123) { // 소문자일 경우
			tmp = (int)a[i];
			acount[tmp - 97]++;
		}
    }
    for(int i=0;i<26;i++){
        if(max<acount[i]){
            max = acount[i];
            tmp = i;
            flag = 0;
        }
        else if(max == acount[i]){
            flag = 1;
        }
    }
    if(flag == 1){
        printf("?");
    } else {
        printf("%c",tmp+65);
    }
    return 0;
}