#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int m,n;
int box[1001][1001];
queue<pair<int, int> > q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; 
void bfs(){
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(box[nx][ny] == 0){
                box[nx][ny] = box[curx][cury] + 1;
                q.push({nx,ny});
            }
        }
    }
    // printf("\n");
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         printf("%d", box[i][j]);
    //     }
    //     printf("\n");
    // }
}
int main(){
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &box[i][j]);
            if(box[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    bfs();
    int result = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(box[i][j] == 0){
                printf("-1\n");
                return 0;
            } if (result < box[i][j]) result = box[i][j];
        }
    }
    cout << result-1 << endl;
    return 0;
}