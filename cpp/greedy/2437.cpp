#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a;
    bool check[1000001] = {false};
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int tmp1;
        cin >> tmp1;
        a.push_back(tmp1);
    }
    check[0] = true;
    sort(a.begin(),a.end());
    int sum = 0;
    
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
        // check[a[i]] = true;
        // sum = sum+a[i];
        // check[sum] = true;
        check[a[i]] = true;
        for(int j=i+1;j<n;j++){
            sum = a[i]+a[j];
            check[sum] = true;
        }
        
    }
    printf("\n");
    for(int i=0;i<1000001;i++){
        if(check[i] == false) {
            printf("%d",i);
            return 0;
        }
    }

    return 0;
}