#include <stdio.h>
int main(){
    int count = -1;
    int num,a;
    scanf("%d", &num);
    for(a = 0;a*5<=num;a++){
        if((num - a*5) % 3 == 0){
            count = a + ((num - a*5) / 3);
        }
    }
    printf("%d", count);
    return 0;
}