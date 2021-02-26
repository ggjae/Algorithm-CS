#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_dfs[25][25];
int map[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> cntvec;
int cnt;
int n;

void dfs(int x,int y){
    cnt++;
    check_dfs[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(map[nx][ny] == 1 && check_dfs[nx][ny] == false) dfs(nx,ny);
    }
}
int main(){
    cin >> n;
    string line;
    // fill_n(check_dfs,25*25,false);
    for(int i=0;i<n;i++){
        cin >> line;
        for(int j=0;j<n;j++){
            map[i][j] = line[j] - '0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == 1 && check_dfs[i][j] == false){
                cnt = 0;
                dfs(i,j);
                cntvec.push_back(cnt);
            }
        }
    }
    sort(cntvec.begin(),cntvec.end());
    cout << cntvec.size() << endl;
    for(int i=0;i<cntvec.size();i++){
        cout << cntvec[i] << endl;
    }
    return 0;
}