#include <iostream>
using namespace std;
 
int arr[100001];
long long int ans;
 
int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int s = 0;
    long long int sum = 0;

    for (int i = s; i < s+K; i++) {
        sum += arr[i];
    }

    ans = sum;
 
    while (true) {
        sum -= arr[s];
        if (s+K >= N) {
            break;
        }
        sum += arr[s+K];
        if (sum > ans) {
            ans = sum;
        }
        s++;
    }
    cout << ans;
    return 0;
}