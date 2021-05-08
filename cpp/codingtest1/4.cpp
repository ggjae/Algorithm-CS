#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool visit[1001];
int n;
int start;
int e;
int cnt = 0;
int dfs(int start, int e, vector<vector<int>> roads, vector<int> traps){
    int i;
    
    return cnt;
    
}
int solution(int n, int start, int e, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    visit[start] = true;
    if(start == e){
        return cnt;
    }
    printf("cnt : %d road size : %d\n",cnt,roads.size());
    if(find(traps.begin(),traps.end(),start) != traps.end()){
        for(int i=0;i<roads.size();i++){
            if(roads[i][1] == start){
                printf("cnt : %d\n",cnt);
                cnt += roads[i][2];
                if(visit[roads[i][0]]) continue;
                solution(n,visit[roads[i][0]],&roads,traps);
            }
        }
    } else {
        for(int i=0;i<roads.size(); i++){
            if(roads[i][0] == start){
                printf("cnt : %d\n",cnt);
                cnt += roads[i][2];
                if(visit[roads[i][1]]) continue;
                solution(n,visit[roads[i][1]],&roads,traps);
            }
        }
    }
    answer = cnt;
    return answer;
}
int main(){
    cout << solution(3,1,3,{{1,2,2},{3,2,3}},{2}) << endl;
    return 0;
}