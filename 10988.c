#include <stdio.h>
#include <string.h>
int main() {
	char a[101],b[101];
    scanf("%s",&a);
    for(int i=1;i<=strlen(a);i++){
        b[i-1] = a[strlen(a)-i];   
    }
    for(int i=0;i<strlen(a);i++){
        if(a[i]==b[i]){
            continue;
        } else{
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}