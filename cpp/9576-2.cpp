#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int t;
    int n,m;
    cin >> t;
    for(int i=0;i<t;i++){
        int cnt = 0;
        cin >> n >> m;
        vector<pair<int, int> > a;
        bool check[1001] = {false};
        for(int i=0;i<m;i++){
            int p,q;
            cin >> p >> q;
            a.push_back(make_pair(p,q));
        }
        sort(a.begin(),a.end());
        // q.push(a.begin());
        // while(!q.empty()){
        //     int t = q.top();
        //     q.pop();
        //     q.push()
        // }
        
        for(int i=0;i<m;i++){
            for(int j=a[i].first;j<=a[i].second;j++){
                if(!check[j]){
                    check[j] = true;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(check[i]) cnt++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}