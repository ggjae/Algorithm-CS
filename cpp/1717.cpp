#include <iostream>
#include <vector>
using namespace std;
int n,m;
int parent[1000001];
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    parent[pb] = pa;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int n,m;
    cin >> n >> m;
    for(int i=0;i<=m;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int tmp1,a,b;
        cin >> tmp1 >> a >> b;
        if(tmp1 == 0){
            uni(a,b);
        } else {
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }

    }
    return 0;
}