#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct info{
    int x,y;
};

info tmp;
int row,col,num,y,x,result=0;
bool check[100][100]={false,};
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int main() {
    cin >>row>>col>>num;
    for(int i=0;i<num;i++){
        cin>>y>>x;
        check[y-1][x-1]=true;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(check[i][j]){
                int cnt=1;
                queue<info> q;
                check[i][j]=false;
                tmp.x=j;
                tmp.y=i;
                q.push(tmp);
                while(!q.empty()){
                    int cx = q.front().x;
                    int cy = q.front().y;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if(nx>=0 && ny>=0 && nx<col && ny<row && check[ny][nx]){
                            check[ny][nx]=false;
                            cnt++;
                            tmp.x=nx;
                            tmp.y=ny;
                            q.push(tmp);
                        }
                    }
                }
                result = max(result,cnt);
            }
        }
    }
    cout<<result;
    return 0;
}