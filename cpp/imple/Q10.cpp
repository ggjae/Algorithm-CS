#include <iostream>
using namespace std;
void match(int arr[58][58], vector<vector<int>> key, int rot, int r, int c){
    int n = key.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(rot == 0){
                arr[r+i][c+j] += key[i][j];
            } else if (rot == 1){
                arr[r+i][c+j] += key[j][n-1-i];
            } else if (rot == 2){
                arr[r+i][c+j] += key[n-1-i][n-1-j];
            } else {
                arr[r+i][c+j] += key[n-1-j][i];
            }
        }
    }
}
bool check(int arr[58][58], int offset, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[offset+i][offset+j] != 1){
                    return false;
            }
        }
    }
    return true;
}
bool main(){
    vector<vector<int>> key;
    vector<vector<int>> lock;
    int offset = key.size()- 1;
    for(int r=0;r<offset+lock.size();r++){
        for(int c =0;c<offset+lock.size();c++){
            for(int rot=0;rot<4;rot++){
                int arr[58][58] = {0};
                for(int i=0;i<lock.size();i++){
                    for(int j=0;j<lock.size();j++){
                        arr[offset+i][offset+j] = lock[i][j];
                    }
                }
                match(arr,key,rot,r,c);
                if(check(arr,offset,lock.size())){
                    return true;
                }
            }
        }
    }
    return false;
}
