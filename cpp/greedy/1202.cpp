#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){ // 
    int n,k;
    long long result = 0;
    vector<pair<int, int> > weight;
    vector<int> maxwei;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int m,v;
        cin >> m >> v;
        weight.push_back(make_pair(m,v));
    }
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        maxwei.push_back(c);
    } // 무게에 비해 가격이 높은 놈을 가져가는게 맞지만
    // 최대무게를 지키면서 가져가려면
    //무게로 일단 정렬하고, 가방도 정렬해서 넣을 수 이씅면 넣어
    // 무게제한에 걸리지않는걸 다 넣는 느낌
    // 다 넣으면 어차피 알아서 정렬되어있응게 젤 큰거 넣으면 되자나
    sort(weight.begin(),weight.end());
    sort(maxwei.begin(),maxwei.end());
    priority_queue<int> pq;
    int idx = 0;
    for(int i=0;i<k;i++){
        while(idx < n && weight[idx].first <= maxwei[i]){
            pq.push(weight[idx++].second);
        }
        if(!pq.empty()){
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;
}