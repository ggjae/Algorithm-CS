#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> edge[1001];
int visit[1001];
void dfs(int start){
    if(visit[start]) return;
    visit[start] = true;
    for(int i=0;i<edge[start].size();i++){
        int x = edge[start][i];
        dfs(x);
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(visit[i] == false){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}