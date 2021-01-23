#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    vector<int> square;
    cin >> n;
    square.push_back(1);
    square.push_back(3);
    for(int i=2;i<n;i++){
        square[i] = (square[i-1] + square[i-2] * 2) % 796796;
    }
    printf("%d",square[n-1]);
    return 0;
}