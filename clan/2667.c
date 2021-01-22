#include <stdio.h>
#include <string.h>
int graph[26][26] = {0, };
int dfsvisit[676] = {0, };
int count[676] = {0, }; 
int j = 0;
int flag = 1;
void DFS(int v, int N){
    dfsvisit[v] = 1;
    for(int i=1;i<=N;i++){
        if(graph[v][i] == 1 && dfsvisit[i] == 0){
            if(flag == 0){
                j++;
            }
            count[j]++;
        } else {
            flag = 0;
            DFS(i,N);
        }
    }
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    DFS(1,N);
    while(j >= 0){
        printf("%d", count[j--]);
    }
    return 0;
}