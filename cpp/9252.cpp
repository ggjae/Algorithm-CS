#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(){
    string a,b;
    string ans = "";
    int LCS[1001][1001] = {0};
    cin >> a;
    cin >> b;
    int x = a.length();
    int y = b.length();
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(a[i-1] == b[j-1]){
                LCS[i][j] = LCS[i-1][j-1]+1;
            } else {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    cout << LCS[x][y] << endl;
    
    while(x!=0 && y!=0){
        if(a[x-1] == b[y-1]){
            ans = a[x-1]+ans;
            x--;
            y--;
        } else if(LCS[x][y] == LCS[x-1][y]){
            x--;
        } else if(LCS[x][y] == LCS[x][y-1]){
            y--;
        }
    }
    if(ans.length()>0) cout << ans;
    return 0;
}