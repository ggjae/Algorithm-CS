#include <iostream>
#include <vector>
#include <algorithm>
#define max(a,b) a>b?a:b
using namespace std;
vector<int> k;
vector<int> amount;
int main(){
    int n, tmp;
    int highk;
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        k.push_back(tmp);
    }
    // cout << "fk!";
    amount.push_back(k[0]) ;
    amount[1] = (max(k[0], k[1]));
    // printf("%d",amount[1]);
    for(int i=2;i<n;i++){
        amount[i] = max(amount[i-1], amount[i-2]+k[i]);
    }
    printf("%d\n",amount[n-1]);
    return 0;
}