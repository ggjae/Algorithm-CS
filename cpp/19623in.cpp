#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > conf;
    vector<pair<double, int> > v;
    queue<pair<int, int> > q;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back(make_pair((b-a)/c,i));
        conf.push_back(make_pair(make_pair(a,b),c));
    }
    sort(v.begin(),v.end());
    int time = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        q.push(conf[v[i].second].first);
        pair<int, int> tmp;
        tmp = q.front();
        q.pop();
        if(time <= tmp.second) {
            time = tmp.first;
            ans += conf[v[i].second].second;
        }
    }
    cout << ans << endl;
    return 0;
}