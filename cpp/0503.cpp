#include <iostream>
using namespace std;
int n=0,m=0,count=0;
char ice[1001][1001] = {0, };

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dfs(int a,int b){
    if(a<= -1 || a >= n || b<= -1 || b>= m){
        return false;
    }
    if(ice[a][b] == '0'){
        ice[a][b] = '1';
        dfs(a-1,b);
        dfs(a,b-1);
        dfs(a+1,b);
        dfs(a,b+1);
        return true;
    }
    return false;
}
// bool dfs(int a, int b){
//     if(a <= -1 || a>=n || b<=-1 || b>=m){
//         return false;
//     }
//     if(ice[a][b] == '0'){
//         ice[a][b] == '1';
//         for(int i=0;i<4;i++){
//             int nx = a + dx[i];
//             int ny = b + dy[i];
//             if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
//             if(graph[nx][ny] == 0) continue;
//             if(graph[nx][ny] == 1){
//                 graph[nx][ny] = graph[x][y] + 1;
//             }
//         }
//     }
// }

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ice[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(i,j) == true){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}