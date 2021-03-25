#include <iostream>
#include <cstring>
#include <algorithm>
 
#define INF 987654321
using namespace std;
 
int N, Answer_Bit;
int MAP[16][16];
int Cost[16][1 << 16];
 
 
int DFS(int Cur_Node, int Cur_Bit)
{
    if (Cur_Bit == Answer_Bit)
    {
        if (MAP[Cur_Node][0] == 0) return INF;
        else return MAP[Cur_Node][0];
    }
 
    if (Cost[Cur_Node][Cur_Bit] != -1) return Cost[Cur_Node][Cur_Bit];
    Cost[Cur_Node][Cur_Bit] = INF;
    
    for (int i = 0; i < N; i++)
    {
        if (MAP[Cur_Node][i] == 0) continue; // 못 갈 때.
        if ((Cur_Bit & (1 << i)) == (1 << i)) continue; // 같은 노드를 보고 있을 때
        
        Cost[Cur_Node][Cur_Bit] = min(Cost[Cur_Node][Cur_Bit], MAP[Cur_Node][i] + DFS(i, Cur_Bit | 1 << i));
    }
    return Cost[Cur_Node][Cur_Bit];
}
 
int main(void)
{
 
    //freopen("Input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    Answer_Bit = (1 << N) - 1;
    memset(Cost, -1, sizeof(Cost));
    cout << DFS(0, 1) << endl;
    return 0;
}
