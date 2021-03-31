#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
queue<int> q;
bool visit[1000];
string person[1000];
unordered_map<string, int> dict;
vector<int> tree[1000];
vector<int> root;
vector<int> node[1000];
vector<int> rnode[1000];
int deg[1000];
// int getindex(string s){
//     for(int i=0;i<n;i++){
//         if(s == person[i]) return i;
//     }
//     return -1;
// }
void bfs(){
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i=0;i<node[f].size();i++){
            int a = node[f][i];
            if(!visit[a]){
                visit[a] = true;
                tree[f].push_back(a);
            }
        }
        for(int i=0;i<rnode[f].size();i++){
            int a = rnode[f][i];
            deg[a]--;
            if(deg[a] == 0) q.push(a);
        }
    }
}
int main(){
    fill_n(deg,1000,0);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> person[i];
    sort(person, person+n);
    for(int i=0;i<n;i++)
        dict[person[i]] = i;
    cin >> m;
    for(int i=0;i<m;i++){
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        int a = dict[tmp1];
        int b = dict[tmp2];
        deg[b]++;
        node[b].push_back(a);
        rnode[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        if(deg[i] == 0) {
            q.push(i);
        }
        if(rnode[i].empty()) root.push_back(i);
    }
    bfs();
    cout << root.size() << endl;
    for(int i=0;i<root.size();i++){
        cout << person[root[i]] << ' ';
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << person[i] << ' ' << tree[i].size();
        vector<string> child;
        for(int j=0;j<tree[i].size();j++){
            child.push_back(person[tree[i][j]]);
        }
        sort(child.begin(),child.end());
        for(int j=0;j<tree[i].size();j++){
            cout << ' ' << child[j];
        }
        cout << '\n';
    }
    return 0;
}