#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    vector<int> ball;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        ball.push_back(tmp1);
    }
    int cnt = 0;
    sort(ball.begin(),ball.end());
    for(int i=0;i<n;i++){
        int a = ball[i];
        for(int j=i;j<n;j++){
            if(a != ball[j]){
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}