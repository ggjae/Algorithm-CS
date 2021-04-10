#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    vector<int> bupum;
    cin >> n;
    for(int i=0;i<n;i++){
        int sell;
        cin >> sell;
        bupum.push_back(sell);
    }
    cin >> m;
    sort(bupum.begin(),bupum.end());
    for(int i=0;i<m;i++){
        int buy;
        cin >> buy;
        if(binary_search(bupum.begin(),bupum.end(),buy)) continue;
        else {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}