#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    vector<int> fr;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        fr.push_back(a);
    }
    sort(fr.begin(),fr.end());
    int count = 0;
    int result = 0;
    for(int i=0;i<fr.size();i++){
        count++;
        if(fr[i] <= count) {
            result++;
            count = 0;
        }
    }
    cout << result << endl;
    return 0;
}