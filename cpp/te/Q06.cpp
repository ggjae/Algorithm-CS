#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int, int> > food_times;
    priority_queue<pair<int, int> > pq;
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        food_times.push_back({i, tmp1});
        pq.push({-tmp1,i}); // 시간, 인덱스
    }
    while(k > -pq.top().first){
        
    }
    
    return 0;
}