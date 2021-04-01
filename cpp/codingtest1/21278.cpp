#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    
    int N,M; 
    cin >> N >> M;
    int arr[101][101];
    
    memset(&arr, 10000, sizeof(arr));
    for(int i = 1; i<=M; i++) {
        int a,b;
        cin>>a>>b;
        arr[a][b] = arr[b][a] = 1;
    }
    
    
    for(int k = 1; k <= N; k++ ) {
        for (int i = 1; i<=N; i++) {
            for(int j = 1; j<=N; j ++ ) {
                if (i == j) arr[i][j] = 0;
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
    int tempt = 0;
    int a,b,c; 
    c = 10000;
    for(int i = 1; i < N; i++) {
        for (int j = i+1; j<=N; j++) {
            tempt = 0;
            for (int k = 1; k<=N; k++ ) {
                tempt += min(arr[k][i], arr[k][j])*2;
            }
            if (tempt <= c) {
                if ((i<a && j<b) || (tempt < c)) {
                    a = i; b = j; c = tempt;
                }
            }
        }
    }
    cout<<a<<' '<<b<<' '<<c;
    return 0;
}
