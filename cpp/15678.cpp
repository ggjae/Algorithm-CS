#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,int> pli;
 
ll n,d,a,now,ans=-1e9;
deque<pli> deq;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>d;
    deq.push_back(pli(0,0));
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        while(!deq.empty()&&deq.front().second+d<i) deq.pop_front();
        now=max(a,a+deq.front().first);
        ans=max(ans,now);
        while(!deq.empty()&&deq.back().first<=now) deq.pop_back();
        deq.push_back(pli(now,i));
    }
    cout<<ans;
    return 0;
}