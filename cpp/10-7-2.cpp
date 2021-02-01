#include <iostream>
using namespace std;
int n,m;
int parent[100001];
int findParent(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}
void unionParent(int x, int y){
    int a = findParent(x);
    int b = findParent(y);
    if(a <b) parent[b] = a;
    else parent[a] = b;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int kind,a,b;
        cin >> kind >> a >> b;
        if(kind == 0){
            unionParent(a,b);
        } else{
            if(findParent(a) == findParent(b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}