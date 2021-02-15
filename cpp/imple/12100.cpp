#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int board[20][20];
int n;
int ans;

void shift(int type)
{
    queue<int> q;
    //숫자들을 큐에 집어놓고 각 행의
    //해당방향 끝에서부터 숫자를 넣기 시작
    switch (type)
    {
        //왼쪽
    case 0:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j])
                    q.push(board[i][j]);
                board[i][j] = 0;
            }
            int idx = 0;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();
                if (board[i][idx] == 0)
                    board[i][idx] = data;
                else if (board[i][idx] == data)
                {
                    board[i][idx] *= 2;
                    //시중에 나와있는 게임과 달리 여러번 합쳐지지 않는다
                    idx++;
                }
                else
                {
                    idx++;
                    board[i][idx] = data;
                }
            }
        }
        break;
        //오른쪽
    case 1:
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (board[i][j])
                    q.push(board[i][j]);
                board[i][j] = 0;
            }
            int idx = n - 1;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();
                if (board[i][idx] == 0)
                    board[i][idx] = data;
                else if (board[i][idx] == data)
                {
                    board[i][idx] *= 2;
                    idx--;
                }
                else
                {
                    idx--;
                    board[i][idx] = data;
                }
            }
        }
        break;
        //위쪽
    case 2:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[j][i])
                    q.push(board[j][i]);
                board[j][i] = 0;
            }
            int idx = 0;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();
                if (board[idx][i] == 0)
                    board[idx][i] = data;
                else if (board[idx][i] == data)
                {
                    board[idx][i] *= 2;
                    idx++;
                }
                else
                {
                    idx++;
                    board[idx][i] = data;
                }
            }
        }
        break;
        //아래쪽
    case 3:
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (board[j][i])
                    q.push(board[j][i]);
                board[j][i] = 0;
            }
            int idx = n - 1;
            while (!q.empty())
            {
                int data = q.front();
                q.pop();
                if (board[idx][i] == 0)
                    board[idx][i] = data;
                else if (board[idx][i] == data)
                {
                    board[idx][i] *= 2;
                    idx--;
                }
                else
                {
                    idx--;
                    board[idx][i] = data;
                }
            }
        }
        break;
    }
}
void dfs(int cnt){
    if(cnt == 5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, board[i][j]);
            }
        }
        return;
    }

    int copyBoard[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            copyBoard[i][j] = board[i][j];
        }
    }


    for(int i=0;i<4;i++){
        shift(i);
        dfs(cnt+1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = copyBoard[i][j];
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> board[i][j];
            
    dfs(0);
    cout << ans << endl;
    return 0;
}