#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool check[100][100];
int map[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int> > q;
int n, m;

int bfs(){
    int curx = 0, cury = 0;
    q.push(make_pair(curx,cury));
    check[curx][cury] = true;

    while(!q.empty()){

        curx = q.front().first;
        cury = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] >= 1 && check[nx][ny] == false){
                q.push(make_pair(nx,ny));
                map[nx][ny] = map[curx][cury] + 1;
                check[nx][ny] = true;
            }
        }
    }
    return map[n-1][m-1];
}
int main(){
    cin >> n >> m;
    string line;
    // fill_n(check,100*100,false);
    for(int i=0;i<n;i++){
        cin >> line;
        for(int j=0;j<m;j++){
            map[i][j] = line[j] - '0';
        }
    }
    int ans = bfs();
    cout << ans << endl;
    return 0;
}