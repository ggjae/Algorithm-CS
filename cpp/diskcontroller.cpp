#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int> > pq;
    for(int i=0;i<jobs.size();i++){
        int start = jobs[i][0];
        int during = jobs[i][1];
        pq.push(-during,i);
    }
    while(!pq.empty()){
        
    }
    return answer;
}