#include <stdio.h>
#define MAX_STACK_SIZE 10000

int main(void){

    int n=0, size=0, value=0,top=-1;
    char ord;
    int stack[MAX_STACK_SIZE]; // stack 선언

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%c %d",&ord,&n);
        if(scanf("push %d",&value)){ // push
            stack[++top] = value;
            size++;
        } else if(scanf("pop")){ // pop
            if(size==0){
                printf("-1 \n");
            }else {
                printf("%d \n",value);
                stack[top--] = value;
                size--;
            }
        } else if(scanf("size")){ //size
            printf("%d \n",size);
        } else if(scanf("empty")){ // empty
            if(top<0){
                printf("1 \n");
            } else{
                printf("0 \n");
            }
        } else if(scanf("top")){ // top
            
            printf("%d \n",stack[top]);

            if(size == 0){
                printf("-1");
            }
        }
    }
    return 0;
}