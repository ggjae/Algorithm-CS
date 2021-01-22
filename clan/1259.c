#include <stdio.h>
int main() {
	int palind[10000];
    int i = 0;
    int tmp,remind;
    while(1){
        scanf("%d",&palind[i]);
        if(palind[i] == 0){
            break;
        }
        i++;
    }
    i = 0;
    remind = 0;
    for(int j=0;j<10000;j++){
        tmp = palind[j];
        if(tmp == 0){
            break;
        }
        while(tmp!=0){
            remind=remind*10;
            remind = remind + tmp%10;
            tmp = tmp/10;
        }
        if(palind[j] == remind){
            printf("yes\n");
        } else {
            printf("no\n");
        }
        remind = 0;
    }
	return 0;
}