#include <iostream>
#include <vector>
using namespace std;
int main(){
    int city;
    vector<long long> length, price;
    long long ans = 0;
    cin >> city;
    long long totlength = 0;
    for(int i=0;i<city-1;i++){
        int tmp;
        cin >> tmp;
        length.push_back(tmp);
    }
    for(int i=0;i<city;i++){
        int tmp;
        cin >> tmp;
        price.push_back(tmp);
    }
    long long minprice = price[0];
    
    for(int i=0;i<city;i++){
        if(price[i] < minprice){
            minprice = price[i];
        }
        ans += minprice * length[i];
    }
    cout << ans;

    return 0;
}