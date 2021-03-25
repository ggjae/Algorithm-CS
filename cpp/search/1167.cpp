#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int> > graph[100001];
bool visit[100001];
int m = 0;
int mnode = 0;
// dfs
void dfs(int curpoint, int cnt){
    if(visit[curpoint]) return;

    visit[curpoint] = true;
    if(m < cnt){
        m = cnt;
        mnode = curpoint;
    }
    for(int i=0;i<graph[curpoint].size();i++){
        dfs(graph[curpoint][i].first, cnt+graph[curpoint][i].second);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        while(true){
            int b, c;
            cin >> b;
            if(b == -1) break;
            cin >> c;
            graph[a].push_back({b,c});
        }
    }
    memset(visit,false,sizeof(visit));
    dfs(1,0);
    memset(visit,false,sizeof(visit));
    m = 0;
    dfs(mnode,0);
    cout << m << endl;

    return 0;
}