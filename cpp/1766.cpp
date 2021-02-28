#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int n,m;
    int result[32001];
    int residx = 0;
    queue<int> q;
    int input_degree[32001];
    vector<int> adj[100001];
    cin >> n >> m;
    fill_n(input_degree, 32001, 0);
    for(int i=0;i<m;i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        input_degree[tmp2]++;

    }
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        if(input_degree[i] == 0){
            pq.push(-i);
        }
    }
    while(!pq.empty()){
        int v = -pq.top();
        pq.pop();
        result[residx++] = v;
        for(int i=0;i<adj[v].size();i++){
            if(--input_degree[adj[v][i]] == 0) {
                pq.push(-adj[v][i]);
            }
        }
    }
    for(int i=0;i<residx;i++){
        cout << result[i] << " ";
    }

    return 0;
}