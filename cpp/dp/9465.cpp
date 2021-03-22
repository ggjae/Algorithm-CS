#include <iostream>
#include <cstring>
 
#define endl "\n"
#define MAX 100010
using namespace std;
 
int N;
int MAP[3][MAX];
int DP[3][MAX];
 
int Max(int A, int  B) { if (A > B) return A; return B; }
 
void Initialize()
{
    memset(DP, 0, sizeof(DP));
}
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
void Solution()
{
    DP[1][1] = MAP[1][1];
    DP[2][1] = MAP[2][1];
    for (int i = 2; i <= N; i++)
    {
        DP[1][i] = Max(DP[2][i - 1], DP[2][i - 2]) + MAP[1][i];
        DP[2][i] = Max(DP[1][i - 1], DP[1][i - 2]) + MAP[2][i];
    }
    cout << Max(DP[1][N], DP[2][N]) << endl;
}
 
void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
