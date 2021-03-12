#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
queue<pair<pair<int, int>, pair<int, int> > > q;
int map[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool visit[1001][1001][2];
int cnt = 1;
void bfs(){
    while(!q.empty()){
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int wall = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == 1 && wall == 1){
                visit[nx][ny][wall] = true;
                q.push({{nx,ny},{wall-1,cnt+1}});
            } if(map[nx][ny] == 0 && !visit[nx][ny][wall]){
                visit[nx][ny][wall] = true;
                q.push({{nx,ny},{wall,cnt+1}});
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        for(int j=0;j<m;j++){
            map[i][j] = tmp[j] - '0';
            if(map[i][j] == 0){
                q.push({{i,j},{wall,cnt}});
            } 
        }
    }

    return 0;
}