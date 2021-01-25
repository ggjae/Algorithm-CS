#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9
int n,m;
int x,k;
vector<pair<int, int> > graph[101];
int d[101];


void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    d[start] = 0;
    pq.push(make_pair(0,start));
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
                printf("now : %d, cost: %d\n",now, cost);
            }
        }
    }
}
int main(){
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(make_pair(b,1));
        graph[b].push_back(make_pair(a,1));
    }

    cin >> x >> k;

    fill_n(d, 101, INF);

    d[0] = 0;
    dijkstra(1);
    int kdistance = d[k];

    fill_n(d, 101, INF);
    d[0] = 0;
    dijkstra(k);
    int xdistance = d[x];
    
    
    printf("kdist = %d, xdist = %d, sum = %d", kdistance, xdistance, kdistance+xdistance);
    return 0;
}