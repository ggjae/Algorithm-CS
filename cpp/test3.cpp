#include <iostream>
#include <queue>
using namespace std;
int dx = {0,0,1,-1};
int dy = {1,-1,0,0};
queue<pair<int, int> > q;
char graph[101][101];
int gp[101][101];
void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx < 0 || nx > m || ny < 0 || ny > n) continue;
            else{
                gp[nx][ny] = gp[x][y] + 1;
            }
        }
    }
    return 0;
}
int main() {
    int m,n;
    
    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
            gp[i][j] = 0;
            if(graph[i][j] == '*'){
                q.push({i,j});
                gp[i][j] = -1;
            }
            
        }
    }
    bfs();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << gp[i][j];
        }
    }
  return 0;
}
