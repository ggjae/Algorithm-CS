#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int mat[1001][1001];
bool visit[1001][1001][2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n,m;
int BFS(){
    queue<pair<pair<int, int>, pair<int, int> > > q; // {x,y} , {벽부술수있는지,cnt}
    q.push({{0,0},{1,1}});
    visit[0][0][1] = true;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int w = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        if(x == n-1 && y == m-1) return cnt;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx>=n || ny <0 || ny>=m) continue;
            if(mat[nx][ny] == 1 && w == 1){
                visit[nx][ny][1] = true;
                q.push({{nx,ny}, {w-1,cnt+1}});
            } if(mat[nx][ny] == 0 && !visit[nx][ny][w]){
                visit[nx][ny][1] = true;
                q.push({{nx, ny}, {w,cnt+1}});
            }
        }
    }
    return -1;

}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        for(int j=0;j<m;j++){
            mat[i][j] = tmp[j] - '0';
        }
    }
    cout << BFS();
    return 0;
}