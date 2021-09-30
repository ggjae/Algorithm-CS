#include <iostream>
using namespace std;
int graph[1001][1001];
int n,m;
bool dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    if(graph[x][y] == 0){
        graph[x][y] = 1;
        dfs(x-1,y);
        dfs(x,y-1);
        dfs(x+1,y);
        dfs(x,y+1);
        return true;
    }
    return false;
}
int main(){
    int res = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(i,j) == true) res++;
        }
    }
    cout << res;
    return 0;
}