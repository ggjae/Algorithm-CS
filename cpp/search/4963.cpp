#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int w,h;
int dy[8] = {1,1,-1,-1,1,-1,0,0};
int dx[8] = {-1,1,-1,1,0,0,1,-1};
int map[50][50];
bool visit[50][50];
void dfs(int x, int y){
    visit[x][y] = true;
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(map[nx][ny] == 0) continue;
        if(map[nx][ny] == 1 && visit[nx][ny] == false){
            dfs(nx,ny);
        }
    }
}
int main(){
    while(true){
        int cnt = 0;
        
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        memset(map,0,sizeof(map));
        memset(visit,false,sizeof(visit));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j] == 1 && visit[i][j] == false){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}