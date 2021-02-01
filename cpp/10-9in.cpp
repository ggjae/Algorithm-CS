#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v;
int indegree[501];
vector<int> graph[501]; // 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트
int times[501];

void topologysort(){
    vector<int> result(501);
    for(int i = 1; i<=v; i++){
        result[i] = times[i];
    }
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
            result[graph[now][i]] = max
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
    cin >> v;
    for(int i=1;i<=v;i++){
        int x;
        cin >> x;
        times[i] = x;
        while(true) {
            cin >> x;
            if(x == -1) break;
            graph[x].push_back(i);
            indegree[b] += 1;
        }
    }
    topologysort();
}