#include <iostream>
using namespace std;
int main(){
    int n = 0;
    int k = 0;
    int count = 0;
    int num_list[11];
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> num_list[i];
    }
    for(int j=n-1;j>=0;j--){
        if (num_list[j] <= k){
            count += k/num_list[j];
            k = k%num_list[j];
        }
            
    }
    cout << count;
    return 0;
}
