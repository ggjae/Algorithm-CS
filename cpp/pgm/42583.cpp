#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int> > q;
    int w = 0;
    int idx = 0;
    while(idx < truck_weights.size() || !q.empty()){
        if(!q.empty()){
            if(q.front().second == answer){
                w -= q.front().first;
                q.pop();
            }
        }
        if((w < weight) && ((weight-w) >= truck_weights[idx]) && idx < truck_weights.size()){
            q.push({truck_weights[idx], answer+bridge_length});
            w += truck_weights[idx];
            idx++;
            answer++;
        } else if(!q.empty()){ // 태울 수 없을 때... 큐가 비지 않았다면 한번에 점프해주는 기능
            answer = q.front().second;
        }
    }
    return answer+1;
}