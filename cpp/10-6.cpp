#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v,e;
int indegree[100001];
vector<int> graph[100001]; // 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트
void topologysort(){
    vector<int> result;
    queue<int> q;

    for(int i=1;i<=v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        result.push_back(now);
        for(int i=0;i<graph[now].size();i++){
            indegree[graph[now][i]] -= 1; // 지금 위치로부터 이어진 놈들 다 -1 하나씩 해줌
            if(indegree[graph[now][i]]== 0){
                q.push(graph[now][i]);
            }
        }
    }
    for (int i=0;i<result.size();i++){
        cout << result[i] << ' ';
    }

}

int main(){
    cin >> v >> e;
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b] += 1;
    }
    topologysort();
}