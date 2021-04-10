#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
int parent[100001];
int result = 0;
int last = 0;
vector<pair<int, pair<int, int> > > edges;

int findParent(int x){
    if(x == parent[x]) return x;
    else return parent[x] = findParent(parent[x]);
}
void unionParent(int x, int y){
    int a = findParent(x);
    int b = findParent(y);
    if(a > b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int cost,a,b;
        cin >> a >> b >> cost;
        edges.push_back(make_pair(cost, make_pair(a,b)));         
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(findParent(a) != findParent(b)){
            unionParent(a,b);
            result += cost;
            last = cost;
        }
    }
    cout << result-last;
    return 0;
}