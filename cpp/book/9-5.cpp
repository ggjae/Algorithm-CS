#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

int dis[30001];
int n,m,start;
vector<pair<int, int> > graph[30001];

void dijkstra(int start){
    dis[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(dis[now] < d) continue; // 현재 노드가 이미 처리된 적 있는지 확인
        for(int i=0;i<graph[now].size();i++){ // 현재 노드와 관련된 놈들 전부 확인하려고
            int cost = d + graph[now][i].second;
            if(cost < dis[graph[now][i].first]){
                dis[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}
int main(){
    cin >> n >> m >> start;
    fill_n(dis,30001,INF);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }
    dijkstra(start);
    int count = 0;
    int max_distance = -1;
    for(int i=1;i<=n;i++){
        if(dis[i] != INF){
            count++;
            max_distance = max(max_distance, dis[i]);
        }
    }
    printf("%d %d\n",count-1,max_distance);
    return 0;
}