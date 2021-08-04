#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int answer = 0;
    for (int i = 1; i < n; i++) {
        answer = max(answer, sum - a[0] - a[n - 1] + a[i]);
    }
    int cur = a[n - 1];
    for (int i = n - 2; i > 0; i--) {
        answer = max(answer, sum - a[0] - a[i] + cur);
        cur += a[i];
    }
    cur = a[0];
    for (int i = 1; i < n - 1; i++) {
        answer = max(answer, sum - a[n - 1] - a[i] + cur);
        cur += a[i];
    }

    cout << answer;

    return 0;
}