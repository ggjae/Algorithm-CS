#include <stdio.h>
void hanoi(int floor){
    if(floor % 2 == 1){ // odd
        printf("1 3");
    } else { // even

    }
}
int main(){
    int a;
    scanf("%d",&a);
    hanoi(a);
    return 0;
}