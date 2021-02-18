#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    
    vector<int> positive;
    vector<int> negative;
    int zero = 0;
    int one = 0;
    int n; 
    cin >> n;
    for (int i=0;i<n;i++) {
        int k; 
        cin >> k;
        if (k == 1) {
            one++;
        }
        else if (k > 0) {
            positive.push_back(k);
        }
        else if (k < 0) {
            negative.push_back(k);
        }
        else zero++;
    }
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());

    if (positive.size() % 2 == 1) positive.push_back(1);
    if (negative.size() % 2 == 1) negative.push_back(zero > 0 ? 0 : 1);
 
    int ans = 0;
    for (int i = 0; i < positive.size(); i += 2) {
        ans += positive[i] * positive[i + 1];
    }
    for (int i = 0; i < negative.size(); i += 2) {
        ans += negative[i] * negative[i + 1];
    }
    ans = ans + one;
    printf("%d", ans);
    return 0;
}
