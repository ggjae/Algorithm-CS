#include <iostream>
using namespace std;
int main(){
    int n = 5;
    int ab[50][50];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&ab[i][j]);
        }
    }
    printf("%d",ab[0][0]);
    return 0;
}