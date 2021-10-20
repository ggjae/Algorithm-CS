#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int board[101][101];
bool Is_There_Snake[101][101];

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };


char swift[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int board_Size,Apple_Cnt; cin >> board_Size >> Apple_Cnt;

	for (int i = 0; i < Apple_Cnt; i++)
	{
		int col, row; cin >> col >> row;
		board[col][row] = 1;
	}

	int swift_Cnt; cin >> swift_Cnt;

	for (int i = 0; i < swift_Cnt; i++)
	{
		int swift_Time;
		char Direction;
		cin >> swift_Time >> Direction;
		swift[swift_Time] = Direction;
	}

	queue<pair<int,int>> snake;

	snake.push({ 1,1 });
	Is_There_Snake[1][1] = true;

	int answer_Time = 0;
	int now_Direction = 0;

	while (1)
	{
		answer_Time++;

		int next_col = snake.back().first + dy[now_Direction];
		int next_row = snake.back().second + dx[now_Direction];

		if (next_col < 1 || next_col > board_Size || next_row < 1 || next_row > board_Size) break;

		snake.push({ next_col,next_row });

		if (swift[answer_Time] == 'D')
		{
			now_Direction += 1;
			if (now_Direction == 4) now_Direction = 0;
		}

		else if (swift[answer_Time] == 'L')
		{
			now_Direction -= 1;
			if (now_Direction == -1) now_Direction = 3;
		}

		if (board[next_col][next_row] == 1)
		{
			board[next_col][next_row] = 0;
		}
		
		else
		{
			if (Is_There_Snake[next_col][next_row] == true) break;
			Is_There_Snake[snake.front().first][snake.front().second] = false;
			snake.pop();
		}

		if (Is_There_Snake[next_col][next_row] == true) break;

		else Is_There_Snake[next_col][next_row] = true;
	
	}

	cout << answer_Time << endl;

	return 0;
}