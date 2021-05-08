#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(-scoville[i]);
    }
    while(-pq.top() < K && pq.size() >= 2){
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        a = a+2*b;
        pq.push(-a);
        answer++;
    }
    if(-pq.top() < K){
        return -1;
    }

    return answer;
}