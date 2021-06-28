#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(){
    string a,b;
    int LCS[1001][1001] = {0};
    cin >> a;
    cin >> b;
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            if(a[i-1] == b[j-1]){
                LCS[i][j] = LCS[i-1][j-1]+1;
            } else {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    cout << LCS[a.length()][b.length()];
    return 0;
}