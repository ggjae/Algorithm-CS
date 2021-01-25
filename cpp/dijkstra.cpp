#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
vector<pair<int, int> > graph[101];
int d[101];
int n,m,start;
void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0,start));
    d[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist) continue;
        for(int i=0;i<graph[now].size();i++){
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}
int main(){
    fill_n(d,101,INF);
    cin >> n >> m >> start;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }
    dijkstra(start);

    for(int i=1;i<=n;i++){
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}