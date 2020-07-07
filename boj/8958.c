#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int a;
    char c[81];
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%s",c);
        int count = 0;
        int sumcount = 0;
        for(int i=0;i<strlen(c);i++){
            if(c[i] == 'O'){
                count++;
                sumcount += count;
            } else {
                count = 0;
            }
        }
        printf("%d\n",sumcount);
    }
    return 0;
}