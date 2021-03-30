#include <iostream>
#include <vector>
using namespace std;
int n,m;
queue<int> 
string person[1000];
vector<int> graph[1000];
int deg[1000];
int getindex(string s){
    for(int i=0;i<n;i++){
        if(s == person[i]) return i;
    }
    return -1;
}
int main(){

    fill_n(deg,1000,0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> person[i];
    }
    cin >> m;
    for(int i=0;i<m;i++){
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        int a = getindex(tmp1);
        int b = getindex(tmp2);
        graph[a].push_back(b);
        deg[a]++;
    }
    for(int i=0;i<n;i++){
        if(deg[i] == 0) {
            q.push(i);
        }
    }
    printf("%d", q.size());
    for(int i=0;i<q.size();i++){
        
    }
    return 0;
}