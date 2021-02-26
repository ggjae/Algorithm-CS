#include <iostream>
using namespace std;
int main(){
    int n = 4, m = 6;
    string line;
    int ab[50][50];
    for(int i=0;i<n;i++){
        cin >> line;
        for(int j=0;j<m;j++){
            ab[i][j] = line[j] - '0';
        }
    }
    printf("%d",ab[0][0]);
    return 0;
}