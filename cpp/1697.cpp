#include <iostream>
#include <queue>
using namespace std;
int n, k;
bool check[100001];
queue<pair<int, int> > q;
void bfs(int start){
    q.push(make_pair(start,0));
    check[start] = true;
    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        if(now == k){
            printf("%d", time);
            return;
        }

        int f = now.first-1;
        int s = now.first+1;
        int d = now.first*2;
        if(s < 100001 && check[f] == false){
            q.push(make_pair(f,cnt));
            check[f] = true;
        }
        if(f >= 0 && check[s] == false){
            q.push(make_pair(s,cnt));
            check[s] = true;
        }
        if(check[d] == false){
            q.push(make_pair(d,cnt));
            check[d] = true;
        }
        for(int i=0;i<q.size();i++){
            cnt--;
        }
    }
}
int main(){
    cin >> n >> k;
    fill_n(check,100001,false);
    bfs(n);
    return 0;
}