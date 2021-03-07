#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m; // m이 수열 합 값, n은 데이터 개수
    cin >> n >> m;
    vector<int> data;
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        data.push_back(tmp1);
    }
    int result = 0;
    int summary = 0;
    int end =0;
    for(int start=0;start<n;start++){
        while(summary < n && end < n){ // 합이 작은 경우에..
            summary += data[end++];
        }
        if(summary == m){
            result++;
        }
        summary -= data[start];
    }
    cout << result;
    return 0;
}