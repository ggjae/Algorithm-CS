#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[1001];
bool visit[1001];
int n,m,v;
queue<int> Q;
void dfs(int start){
    int i;
    visit[start] = true;
    cout << start << ' ';
    for(int i=0;i<graph[start].size(); i++){
        int next = graph[start][i];
        if(visit[next]) continue;
        dfs(next);
    }
}
void BFS(int start) {
  memset(visit, false, sizeof(visit));
  visit[start] = true;
  Q.push(start);

  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    cout << x << ' ';
    for (int i=0; i < graph[x].size(); i++) {
      int next = graph[x][i];
      if (!visit[next]) {
        visit[next] = true;
        Q.push(next);
      }
    }
  }
}
int main(){
    int n,m,v;
    cin >> n >> m >> v;
    fill(visit,visit+1001,false);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(v);
    // bfs(v);
    return 0;
}