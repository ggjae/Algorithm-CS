#include <stdio.h>
#include <string.h>
int graph[101][101] = {0, };
int dfsvisit[101] = {0, };
int count = 0;
void DFS(int v, int N){
    dfsvisit[v] = 1;
    for(int i=1;i<=N;i++){
        if(graph[v][i] == 1 && dfsvisit[i] == 0){
            count++;
            DFS(i,N);
        }
    }
}
int main(){
    int N,E;
    int a,b;
    scanf("%d",&N);
    scanf("%d",&E);
    for(int i=0;i<E;i++){
        scanf("%d %d",&a,&b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    DFS(1,N);
    printf("%d",count);
    return 0;
}