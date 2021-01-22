#include <stdio.h>
int graph[1001][1001] = {0};
int dfsvisit[1001] = {0};
int bfsvisit[1001] = {0};
int queue[1001];

void DFS(int v, int N){
    dfsvisit[v] = 1;
    printf("%d ", v);
    for(int i=0;i<=N;i++){
        if(graph[v][i] == 1 && dfsvisit[i] == 0){
            DFS(i,N);
        }
    }
}
void BFS(int v,int N){
    int front = 0;
    int rear = 0;
    int pop;
    printf("%d ",v);
    queue[0] = v;
    rear++;
    bfsvisit[v] = 1;
    while(front<rear){
        pop = queue[front];
        front++;
        for(int i=1;i<=N;i++){
            if(graph[pop][i] == 1 && bfsvisit[i] == 0){
                printf("%d ",i);
                queue[rear] = i;
                rear++;
                bfsvisit[i] = 1;
            }
        }
    }
}
int main(){
    int N,M,V;
    int x,y;
    scanf("%d %d %d",&N,&M,&V);
    for(int i=0;i<M;i++){
        scanf("%d %d",&x,&y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    DFS(V,N);
    printf("\n");
    BFS(V,N);
    return 0;
}