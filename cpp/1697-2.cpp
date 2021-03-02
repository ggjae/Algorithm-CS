#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001
int n, k;
bool check[MAX];
int cnt = 0;
queue<int> q;
void bfs(int start){
    q.push(start);
    check[start] = true;
    while(!q.empty()){
        int Q=q.size();
        for(int i=0;i<Q;i++){
            int now = q.front();
            q.pop();
            if(now == k){
                printf("%d", cnt);
                return;
            }
            int f = now-1;
            int s = now+1;
            int d = now*2;
            if(!check[f] && f >= 0){
                q.push(f);
                check[f] = true;
            }
            if(!check[s] && s < MAX){
                q.push(s);
                check[s] = true;
            }
            if(!check[d] && d < MAX){
                q.push(d);
                check[d] = true;
            }
        }
        cnt++;
    }
}
int main(){
    cin >> n >> k;
    bfs(n);
    return 0;
}