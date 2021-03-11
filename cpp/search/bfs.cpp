#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m;
queue<pair<int, int> > q;
int tomato[1001][1001];
void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(tomato[nx][ny] == 0) {
                tomato[nx][ny] = tomato[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> tomato[i][j];
            if(tomato[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    bfs();
    int result = -1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(tomato[i][j] == 0){
                printf("-1");
                return 0;
            }
            if(result < tomato[i][j]){
                result = tomato[i][j];
            }
        }
    }
    printf("%d",result-1);
    return 0;
}