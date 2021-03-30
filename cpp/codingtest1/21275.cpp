#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// a = 97, z = 122
long long f(string a, int idx){
    long long d = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] >= 'a') {
            if(idx <= a[i] - 'a' + 10) return -1;
            d = d * idx + (a[i] - 'a' + 10);
        } else {
            if(a[i]-'0' >= idx) return -1;
            d = d * idx + (a[i] - '0');
        }
    }
    if(d < 0) return -1;
    return d;
}
int main(){
    string A,B;
    cin >> A >> B;
    queue<pair<long long, pair<int, int> > > q;
    for(int i=2;i<=36;i++){
        for(int j=2;j<=36;j++){
            if(i == j) continue;
            else {
                long long a = f(A,i);
                if(a < 0) break;
                long long b = f(B,j);
                if(a == b){
                    q.push({a,{i,j}});
                }
                if(q.size() == 2){
                    break;
                }
            }
        }
    }
    if(q.size() == 0) printf("Impossible");
    else if(q.size() == 1) printf("%lld %d %d",q.front().first, q.front().second.first, q.front().second.second);
    else printf("Multiple");
    return 0;
}