#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
int main(){
    int t;
    cin >> t;
    vector<pair<int, int> > va;
    vector<pair<int, int> > vb;
    for(int i=0;i<t;i++){
        int a;
        cin >> a;
        for(int i=0;i<a;i++){
            int b,c;
            cin >> b >> c;
            va.push_back(make_pair(b,c));
        }
        sort(va.begin(),va.end());
        int maxsec = va[0].second;
        int count = 1;
        for(int i=1;i<a;i++){
            if(maxsec > va[i].second){`
                count++;
                maxsec = va[i].second;
            }
        }
        // sort(va.begin(),va.end(),cmp);
        // int maxfir = va[0].first;
        // for(int i=1;i<a;i++){
        //     if(maxfir > va[i].first){
        //         count++;
        //     }
        // }
        cout << count << endl;
        va.clear();
    }
    return 0;
}