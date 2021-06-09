#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0;
    vector<pair<int, int> > vp;
    stack<pair<int, int> > st;
    for(int i=0;i<n;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        vp.push_back({tmp1,tmp2});
    }
    st.push({vp[0].first, vp[0].second});
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().second > vp[i].second){
            ans++;
            st.pop();
        }
        if(!st.empty() && st.top().second == vp[i].second) continue;
        st.push({vp[i].first,vp[i].second});
    }
    while(!st.empty() && st.top().second > 0){
        st.pop();
        ans++;
    }
    cout << ans;
    return 0;
}