#include <stdio.h>
#include <string.h>
int main() {
	char word[1000001];
    int count = 0;
    int flag = 1;
    scanf("%[^\n]",&word);
    for(int i=0;i<strlen(word);i++){
        if(word[i] != ' ' && flag == 1){
            flag = 0;
            count++;
        } else if(word[i] == ' '){
            flag = 1;
        }
    }
    printf("%d",count);

    return 0;
}