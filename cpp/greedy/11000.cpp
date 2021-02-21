#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int n,s;
    int start,end;
    cin >> n;
    vector<pair<int, int> > lecture;
    priority_queue<int, vector<int>, greater<int> > pq;
    int count = 0;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        lecture.push_back(make_pair(a,b));
    }
    sort(lecture.begin(),lecture.end());
    pq.push(lecture[0].second);
    int max = -1;
    for(int i=1;i<lecture.size();i++){
        start = lecture[i].first;
        end = lecture[i].second;
        if(pq.top() > start){
            pq.push(end);
        } else {
            pq.pop();
            pq.push(end);
        }
        s = pq.size();
        if(max < s) max = s;
    }
    cout << s << endl;
    return 0;
}