#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n,k,l;
int map[101][101] = {0};
vector<pair<int, char> > v;
int turn(int d, char c){
    if(c == 'L'){
        if(d == 0) return 3;
        else if (d == 1) return 2;
        else if (d == 2) return 0;
        else return 1;
    } else if (c == 'D'){
        if(d == 0) return 2;
        else if(d == 1) return 3;
        else if (d == 2) return 1;
        else return 0;
    }
}
int main(){
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        a = a-1;
        b = b-1;
        map[a][b] = 1;
    }
    cin >> l;
    for(int i=0;i<l;i++){
        int a;
        char b;
        cin >> a >> b;
        p.push_back(make_pair(a,b));
    }
    deque<pair<int, int> > q;
    int x = 0, int y = 0, int d = 0, int time = 0, int idx = 0;
    q.push_back(make_pair(x,y));
    map[x][y] = 2;
    while(true){
        time++;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if((nx < 0 || ny < 0 || nx >= N || ny >= N) || map[nx][ny] == 2){
            break;
        } else if(map[nx][ny] == 0){
            map[nx][ny] = 2;
            map[q.back().first][q.back().second] = 0;
            q.pop_back();
            q.push_front(make_pair(nx,ny));
        } else if (map[nx][ny] == 1){
            map[nx][ny] = 2;
            q.push_front(make_pair(nx, ny));
        }
        if(idx < v.size()){
            if(time == v[idx].first){
                if(v[idx].second == 'L') d = turn(d, 'L');
                else d = turn(d,'D');
                idx++;
            }
        }
        x = nx;
        y = ny;
    }
    cout << time << endl;
    return 0;
}