#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int> > q;
    int idx = 0;
    priority_queue<int> pq;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    int rank = 1;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        if(pq.top() == cur.first){
            if(location == cur.second) answer = rank;
            pq.pop();
            q.pop();
            rank++;
        } else {
            q.pop();
            q.push(cur);
        }
    }
    return answer;
}