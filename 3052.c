#include <stdio.h>
#include <string.h>
int main() {
	int value[10];
    int remind[10];
    int difcount = 0;
    int flag = 0;
    for(int i = 0;i<10;i++){
        scanf("%d",&value[i]);
        remind[i] = value[i]%42;
    }
    for(int i=0;i<10;i++){
        difcount++;
        for(int j=i+1;j<10;j++){
            if(remind[i]==remind[j]){
                flag = 1;
            }
        }
        if(flag == 1){
            difcount--;
        }
        flag = 0;
    }
    printf("%d",difcount);
    return 0;
}