#include <iostream>
using namespace std;
int baechu[50][50] = {0};
int n=0,m=0,k=0,test=0,x=0,y=0;
bool dfs(int x,int y){
    if(x <= -1 || x >= m || y <= -1 || y >= n) return false;
    if(baechu[x][y] == 1){
        baechu[x][y] = 0;
        dfs(x-1,y);
        dfs(x,y-1);
        dfs(x+1,y);
        dfs(x,y+1);
        return true;
    }
    return false;
}
int main(){
    int count=0;
    cin >> test;
    for(int i=0;i<test;i++){
        count = 0;
        cin >> m >> n >> k;
        for(int j=0;j<k;j++){
            cin >> x >> y;
            baechu[x][y] = 1;
        }
        for(int p=0;p<m;p++){
            for(int q=0;q<n;q++){
                if(dfs(p,q) == true){
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}