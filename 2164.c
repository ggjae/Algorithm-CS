#include <stdio.h>
int a[1000001];
int main(){
    int n;
    scanf("%d",&n);
    int front = 1;
    int rear = n;
    int count = n;
    for(int i=1;i<=n;i++){
        a[i] = i;
    }
    if(n == 1){
        printf("1");
        return 0;
    } else if(n == 2){
        printf("2");
        return 0;
    } else {
        while(count!=2){
            front++;
            a[++rear] = a[front];
            count--;
            front++;
        }
        printf("%d",a[front-1]);
    }
    
    return 0;
}