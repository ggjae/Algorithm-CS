#include <stdio.h>
#include <string.h>
int main(){
    char a[101];
    int count = 0;
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++){
        if(a[i] == '='){
            if(a[i-1] == 'c'){
                count--;
            }
            else if(a[i-1] == 'z'){
                count--;
                if(a[i-2] == 'd'){
                    count--;
                }
            } else if(a[i-1] == 's'){
                count--;
            }
        } else if(a[i] == '-'){
            if(a[i-1] == 'c'){
                count--;
            } else if(a[i-1] == 'd'){
                count--;
            }
        } else if(a[i] == 'j' && (a[i-1] == 'l' || a[i-1] == 'n')){
            count--;
        }
        count++;
    }
    printf("%d",count);
}