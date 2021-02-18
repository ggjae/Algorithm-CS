#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n;
    priority_queue<int> card;
    cin >> n;
    int ans = 0;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        card.push(-tmp);
    }
    int cnt = 0;
    while(!card.empty()){}
        // if(cnt == n-1) break/;
        int tmp1 = -card.top();
        card.pop();
        int tmp2 = -card.top();
        card.pop();
        card.push(-(tmp1+tmp2));
        ans += tmp1+tmp2;
        cnt++;
    }
    
    cout << ans;
    // if(card.size() % 2 == 1){
        
    // }
    return 0;
}