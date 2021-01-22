#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
    if(a>b) return true;
    else return false;
}

int main(){
    int n = 0;
    int num[501];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    // sort(num,num+n,greater<int>());
    sort(num,num+n,compare); // true가 1빠따..인것같은데 ?
    for(int j=0;j<n;j++){
        cout << num[j] << " ";
    }
}