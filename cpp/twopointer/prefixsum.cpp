#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> data;
    int sum = 0;
    vector<int> sumdata;
    sumdata.push_back(0);
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        data.push_back(tmp1);
        sum+= tmp1;
        sumdata.push_back(sum);
    }
    // 데이터를 받았으면, 구간합을 미리 구해놓는 것.
    for(int i=0;i<=n;i++){
        printf("%d ",sumdata[i]);
    }
    // 1번째값부터 3번째값까지의 합이라면, sumdata[3] - sumdata[0]
    // 매 쿼리마다 L과 R만 안다면 구간합을 빠르게 구할 수 있다.
    return 0;
}