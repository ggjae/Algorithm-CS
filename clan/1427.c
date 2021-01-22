#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;
    int a[11];
    int count = 0;
    int i = 0;
    scanf("%d",&number);
    while(number != 0){
        a[i++] = number % 10;
        number = number / 10;
    
    }
    for(int j=1;j<i;j++){
        count = j;
        while(count>0 && a[count]>a[count-1]){
            int tmp = a[count];
            a[count] = a[count-1];
            a[count-1] = tmp;
            count--;
        }
    }

    for(int j=0;j<i;j++){
        printf("%d",a[j]);
    }
    return 0;
}