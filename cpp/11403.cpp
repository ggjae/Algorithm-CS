#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int graph[101][101];
bool visit[101] = {false};
int n;
void dfs(int start){
    for(int i=0;i<n;i++){
        if(graph[start][i] == 1 && !visit[i]){
            visit[i] = true;
            dfs(i);
        }
    }
}
int main(){
    cin >> n;
    fill(&graph[0][0],&graph[100][101],0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }

    for(int i=0;i<n;i++){
        fill_n(visit,101,false);
        dfs(i);
        for(int j=0;j<n;j++){
            if(visit[j]) graph[i][j] = 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}