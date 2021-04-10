#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    vector<int> dduck;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        dduck.push_back(a);
    }
    sort(dduck.begin(),dduck.end());
    
    int start = 0;
    int result = 0;
    int end = dduck[n-1];
    while(start<=end){
        int sum = 0;
        int mid = (start + end) / 2;
        for(int i=0;i<n;i++){
            if(dduck[i] > mid) sum += dduck[i] - mid;
        }
        if(sum >= m){
            // printf("test: %d %d %d %d\n", start, end, mid, sum);
            result = mid;
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    cout << result << endl;
    return 0;
}