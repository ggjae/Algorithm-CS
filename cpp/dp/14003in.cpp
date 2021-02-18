#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
int ind = 0;
int res[1000001];
pair<int,int> p[1000001];

int main(void) {

    stack<int> ans;
    int n; 
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i == 0) {
            res[ind] = arr[i];
            p[i] = make_pair(ind, arr[i]);
        }
        else if(res[ind] < arr[i]) {
            res[++ind] = arr[i];
            p[i] = make_pair(ind, arr[i]);
        }
        else {
            int tmp = lower_bound(res, res+ind, arr[i]) - res;
            res[tmp] = arr[i];

            p[i] = make_pair(tmp, arr[i]);
        }
    }
    cout<<ind+1<<'\n';

    int cp = ind;

    for(int i = n-1; i >= 0; i--) {
        if(p[i].first == cp) {
            ans.push(p[i].second);
            cp--;
        }
    }

    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
    return 0;
}