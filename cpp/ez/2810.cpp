#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<char> seat;
    cin >> n;
    int lcount = 0;
    for(int i=0;i<n;i++){
        char a;
        cin >> a;
        if(a == 'L') lcount++;
        seat.push_back(a);
    }
    // printf("%d",lcount);
    lcount = lcount/2;
    if(lcount == 0){
        cout << n;
    } else {
        cout << n - lcount + 1;
    }
    return 0;
}