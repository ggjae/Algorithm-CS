#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> v;
    queue<pair<int, int> > q;
    for(int i=0;i<priorities.size();i++){
        q.push({i,priorities[i]});
    }
    sort(priorities.begin(),priorities.end(),greater<>());
    int idx = 0;
    while(!q.empty()){
        int index = q.front().first;
        int priority = q.front().second;
        q.pop();
        if(priority == priorities[idx]){
            idx++;
            v.push_back(index);
        } else {
            q.push({index, priority});
        }
    }
    for(int i=0;i<v.size();i++){
        if(location == v[i]){
            answer = i;
            break;
        }
    }
    return answer+1;
}
int main(){
    solution({2,1,3,2},2);
    return 0;
}