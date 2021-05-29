#include <string>
#include <vector>

using namespace std;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> coninfo(n+1);
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, 0);
    queue<int> q;
    
    for(int i=0;i<edge.size();i++){
        int start = edge[i][0];
        int end = edge[i][1];

        coninfo[start].push_back(end); // 인접 리스트
        coninfo[end].push_back(start);
    }
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int startnode = q.front();
        q.pop();
        for(int i=0;i<coninfo[startnode].size();i++){
            int endnode = coninfo[startnode][i];
            if(!visited[endnode]){
                visited[endnode] = true;
                distance[endnode] = distance[startnode] + 1;
                q.push(endnode);
            }
        }
    }
    sort(distance.begin(),distance.end(),greater<>());
    for(auto d : distance){
        if(d == distance[0]) answer++;
    }
    return answer;
}