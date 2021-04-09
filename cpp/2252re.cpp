#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,m;
    int indegree[32001];
    int residx = 0;
    int result[32001];
    memset(result,0,sizeof(result));
    priority_queue<int> pq;
    vector<int> adj[32001];
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        indegree[tmp2]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            pq.push(-i);
        }
    }
    while(!pq.empty()){
        int now = -pq.top();
        pq.pop();
        result[residx++] = now;
        for(int i=0;i<adj[now].size();i++){
            indegree[adj[now][i]]--;
            if(indegree[adj[now][i]] == 0){
                pq.push(-adj[now][i]);
            }
        }
    }
    return 0;
}