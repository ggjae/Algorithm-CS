#include <iostream>
#include <vector>
// 무방향 그래프에서의 사이클 찾기!
// 부모노드를 이용하기. 서로소 집합.
// union과 find를 이용해서,,
using namespace std;

// 노드의 개수(V)와 간선(Union 연산)의 개수(E)
// 노드의 개수는 최대 100,000개라고 가정
int v, e;
int parent[100001]; // 부모 테이블 초기화
vector<pair<int, pair<int, int> > > edges;

// 특정 원소가 속한 집합을 찾기
int findParent(int x) {
    // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {
    cin >> v >> e;

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }
    int result = 0;

    bool cycle = false; // 사이클 발생 여부

    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back(make_pair(cost,make_pair(a,b)));
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(findParent(a) != findParent(b)){
            unionParent(a, b);
            result += cost;
        }
    }
}
