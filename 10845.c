#include <stdio.h>
#include <string.h>
int len(int stack[]){
    int count = 0;
    int i = 0;
    while(stack[i] != 0){
        count++;
        i++;
    }
    return count;
    
}
void push(int x,int stack[]){
    stack[len(stack)] = x;
}
void pop(int stack[]){
    if(len(stack)!=0){
        printf("%d\n", stack[len(stack)-1]);
        stack[len(stack)-1] = 0;
    } else {
        printf("-1\n");
    }
}
void top(int stack[]){
    if(len(stack)!=0){
        printf("%d\n",stack[len(stack)-1]);
    } else {
        printf("-1\n");
    }
}
void empty(int stack[]){
    if(len(stack) == 0){
        printf("1\n");
    } else {
        printf("0\n");
    }
}
void size(int stack[]){
    printf("%d\n",len(stack));
}
int main() {
    int stack[10001] = {0, };
    char com[13];
    int n,num;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&com);
        if(!strcmp(com,"pop")){
            pop(stack);
        } else if(!strcmp(com, "top")){
            top(stack);
        } else if(!strcmp(com, "empty")){
            empty(stack);
        } else if(!strcmp(com, "size")){
            size(stack);
        } else{
            scanf("%d", &num);
            push(num,stack);
        }
    }
    return 0;
}
