#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10001

int main(void){

    int n=0, size=0, value=0,top=-1;
    char ord[13];
    int stack[MAX_STACK_SIZE]; // stack 선언

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",ord);
        if(!strcmp(ord,"pop")){ // pop
            if(size==0){
                printf("-1\n");
            }else {
                stack[top--] = value;
                size--;
                printf("%d\n",stack[top]);
            }
        } else if(!strcmp(ord,"size")){ //size
            printf("%d\n",size);
        } else if(!strcmp(ord,"empty")){ // empty
            if(top<0){
                printf("1\n");
            } else{
                printf("0\n");
            }
        } else if(!strcmp(ord,"top")){ // top

            if(size == 0){
                printf("-1\n");
            } else{
                printf("%d\n",stack[top-1]);
            }
        }
        else if(!strcmp(ord,"back")){ // top

            if(size == 0){
                printf("-1\n");
            } else{
                printf("%d\n",stack[top-1]);
            }
        }
        else if(!strcmp(ord,"front")){ // top

            if(size == 0){
                printf("-1\n");
            } else{
                printf("%d\n",stack[top-1]);
            }
        }
        else{ // push
            scanf("%d",&value);
            stack[top++] = value;
            size++;
        }
    }
    return 0;
}