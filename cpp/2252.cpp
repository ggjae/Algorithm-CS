#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,m;
    int result[32001];
    int residx = 0;
    vector<int> adj[32001];
    priority_queue<int> pq;
    int idgree[32001];
    fill_n(idgree,32001,0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        idgree[tmp2]++;
    }
    for(int i=1;i<=n;i++){
        if(idgree[i] == 0){
            pq.push(-i);
        }
    }
    while(!pq.empty()){
        int now = -pq.top();
        pq.pop();
        result[residx++] = now;
        for(int i=0;i<adj[now].size();i++){
            if(--idgree[adj[now][i]] == 0){
                pq.push(-adj[now][i]);
            }
        }
    }
    for(int i=0;i<residx;i++){
        printf("%d ", result[i]);
    }
    return 0;
}