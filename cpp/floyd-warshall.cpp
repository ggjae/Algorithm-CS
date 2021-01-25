#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9
int main(){
    int n,m; // 101개를 INF로 초기화시킨 벡터로 그래프를 초기화.
    vector<vector<int> > graph(101,vector<int>(101,INF));
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        graph[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                graph[j][k] = min(graph[j][k], graph[j][i]+graph[i][k]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}