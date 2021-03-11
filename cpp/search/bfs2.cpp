#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int tomato[101][101][101];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};
int m,n,h;
queue<pair<pair<int, int>, int> > q;
void bfs(){
    while(!q.empty()){
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curz = q.front().second;
        q.pop();
        for(int i=0;i<6;i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            int nz = curz+dz[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if(tomato[nx][ny][nz] == 0){
                tomato[nx][ny][nz] = tomato[curx][cury][curz] + 1;
                q.push({{nx,ny},nz});
            }
        }
    }
}
int main(){
    cin >> m >> n >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1) q.push({{i,j},k});
            }
        }
    }
    int result = -1;
    bfs();
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(tomato[i][j][k] == 0) {
                    printf("-1");
                    return 0;
                }
                if(result < tomato[i][j][k]){
                    result = tomato[i][j][k];
                }
            }
        }
    }
    printf("%d",result-1);
    return 0;
}