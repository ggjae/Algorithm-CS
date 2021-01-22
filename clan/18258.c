#include <stdio.h>
#include <string.h>
int queue[2000001];
int main(){
    int n;
    int front = 0;
    int rear = 0;
    char comm[15];
    int size = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",comm);
        if(!strcmp(comm,"push")){
            scanf("%d", &queue[rear++]);
            size++;
        } else if (!strcmp(comm,"front")){
            if(size == 0){
                printf("-1\n");
            } else {
                printf("%d\n", queue[front]);
            }
        } else if (!strcmp(comm,"back")){
            if(size == 0){
                printf("-1\n");
            } else {
                printf("%d\n", queue[rear-1]);
            }
        } else if (!strcmp(comm,"size")){
            printf("%d\n",size);
        } else if (!strcmp(comm,"pop")){
            if(size == 0){
                printf("-1\n");
            } else {
                printf("%d\n",queue[front++]);
                size--;
            }
            
        } else if (!strcmp(comm,"empty")){
            if(size == 0){
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
}