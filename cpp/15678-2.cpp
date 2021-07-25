#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <math.h>
#define st first
#define nd second
#define MAX 100001
using namespace std;
using p = pair<long long, int>;
priority_queue<p> pq; // st : value, nd : index
long long dp[MAX];
int arr[MAX];
int n,d;

void solution() {
  dp[0] = arr[0];
  pq.push({dp[0], 0});
  for (int i=1;i<n;i++) {
    dp[i] = arr[i];
    while(!pq.empty()) {
      p cur = pq.top();
      if (abs(i - cur.nd) <= d) {
        dp[i] = max(cur.st + arr[i], dp[i]);
        pq.push({dp[i], i});
        break;
      } else pq.pop();
    }
  }
  cout << *max_element(dp, dp+n) << "\n";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d;
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  solution();
}