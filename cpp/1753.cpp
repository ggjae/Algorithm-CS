#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int v,e,k;
vector<pair<int, int> > graph[20001];
// int check[20001];
int d[20001];
void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
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
    cin >> v >> e;
    cin >> k;
    for(int i=0;i<e;i++){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        graph[tmp1].push_back({tmp2,tmp3});
    }
    for(int i=1;i<=v;i++) d[i] = INF;
    dijkstra(k);
    for (int i = 1; i <= v; i++) {
		if (d[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", d[i]);
	}
    return 0;
}