#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 999999999 // 101개 블록을 쓰는 벡터
int n,m,start; // 노드의 개수, 엣지의 개수, 시작노드 입력받기
vector<pair<int,int> > adj[101]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 2차원 벡터..?
bool visit[101];
int dist[101];
// 
int getsmallestnode(){
    int min_value = INF;
    int index = 0;
    for(int i=1;i<n+1;i++){
        if(dist[i] < min_value && !visit[i]){
            index = i;
            min_value = dist[i];
        } // 가장 가까운 점을 찾는 과정... closest를 전부 돌면서 젤 짧은 거리 찾아
    }
    return index;
}
void dijkstra(int start){
    dist[start] = 0;
    visit[start] = true;
    for(int i=0;i<adj[start].size();i++){
        dist[adj[start][i].first] = adj[start][i].second;
    }
    for(int i=0;i<n-1;i++){
        int now = getsmallestnode();
        visit[now] = true;
        for(int j=0;j<adj[now].size();j++){
            int cost = dist[now] + adj[now][j].second;
            if(cost < dist[adj[now][j].first]){
                dist[adj[now][j].first] = cost;
            }
        }
    }
}
int main(){
    
    cin >> n >> m >> start;
    adj[0].push_back(make_pair(0,0));
    fill_n(dist,n+1,INF);
    fill_n(visit,n+1,false);
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        // a번 노드에서 b번 노드로 가는 비용이 c다..
        adj[a].push_back(make_pair(b,c));
    }
    dijkstra(start);
    for(int i=1;i<n+1;i++){
        if(dist[i] == INF){
            printf("INF\n");
        } else printf("%d\n", dist[i]);
    }
}