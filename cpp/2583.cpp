#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int m=0,n=0,k=0,x=0,y=0,x1=0,y1=0;
int square[100][100] = {0, };
int arr[10000];
int squarecount = 0;
int arrcount = 0;
bool dfs(int x,int y){
    if(x <= -1 || x >= m || y <= -1 || y >= n) return false;
    if(square[x][y] == 0){
        squarecount++;
        square[x][y] = 1;
        dfs(x-1,y);
        dfs(x,y-1);
        dfs(x+1,y);
        dfs(x,y+1);
        return true;
    }
    return false;
}
int main(){
    cin >> m >> n >> k;
    for(int i=0;i<k;i++){
        cin >> x >> y;
        cin >> x1 >> y1;
        for(int j=x;j<x1;j++){
            for(int k=y;k<y1;k++){
                square[k][j] = 1;
            }
        }
    }
    for(int p=0;p<m;p++){
        for(int q=0;q<n;q++){
            if(square[p][q] == 0){
                squarecount = 0;
                if(dfs(p,q) == true){
                    arr[arrcount++] = squarecount;
                }
            }
        }
    }
    sort(arr, arr+arrcount);
    cout << arrcount << endl;
    for(int i=0;i<arrcount;i++){
        cout << arr[i] << " ";
    }
    return 0;
}