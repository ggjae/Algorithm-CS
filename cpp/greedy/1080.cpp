#include <iostream>
#include <vector>
using namespace std;
char mat[51][51];
char ansmat[51][51];
void reverse(int x, int y){
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(mat[i][j] == '1') mat[i][j] = '0';
            else mat[i][j] = '1';
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            // printf("i : %d j : %d mat[i][j] : %c\n",i,j,mat[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ansmat[i][j];
            // printf("i : %d j : %d mat[i][j] : %c\n",i,j,mat[i][j]);
        }
    }
    // cout << "ajdi";
    if(n < 3 || m < 3){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] != ansmat[i][j]){
                    cout << -1;
                    return 0;
                }
            }
        }
        cout << 0;
        return 0;
    }
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(mat[i][j] != ansmat[i][j]){
                reverse(i,j);
                count++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] != ansmat[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    cout << count;
    return 0;
}