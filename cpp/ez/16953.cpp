#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<pair<long long, long long> > q;
long long a;
int b;
int cnt = 0;
void bfs(){
    q.push(make_pair(a,0));
    while(q.size() != 0){
        pair<long long, long long> m = q.front();
        q.pop();
        if(m.first == b){
            cout << m.second + 1 << endl;
            return;
        } else if(m.first > b){
            continue;
        }

        long long tmp1 = 2 * m.first;
        long long tmp2 = 10 * m.first+1;
        q.push(make_pair(tmp1, m.second+1));
        q.push(make_pair(tmp2, m.second+1));
    }
    cout << -1 << endl;
}
int main(){
    cin >> a >> b;
    bfs();
    return 0;
}