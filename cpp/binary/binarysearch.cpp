#include <iostream>
#include <vector>

using namespace std; // 벡터 &을 빼주면, 벡터 값을 카피하기때문에 시간복잡도가 N
int binarysearch(vector<int>& arr, int target, int start, int end){
    while(start <= end){
        int mid = (start+end) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}
int n, target;
vector<int> arr;
int main(void){
    cin >> n >> target;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int result = binarysearch(arr, target, 0, n-1);
    if(result == -1){
        cout << "원소가 존재하지 않음" << endl;
    } else {
        cout << result + 1 << endl;
    }
    return 0;
}