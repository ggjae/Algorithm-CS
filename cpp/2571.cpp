#include<bits/stdc++.h>

using namespace std;

int board[101][101], v[101][101];

int find(int x, int y);
int getans(int x, int y, int h, int w);
void draw(int x, int y);

int main()
{
	int t;
	cin >> t;
	int x, y;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		draw(x, y);
	}
	
	int ans = 100;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (board[i][j] == 1)
				ans = max(ans,find(i, j));
	cout << ans;	
	return 0;
}
int find(int x,int y)
{
	int ans = 100;
	for (int i = 0; i <= 100; i++) {
		if (x + i > 100)break;
		for (int j = 0; j <= 100; j++) {
			if (y + j > 100)break;
			ans = max(ans, getans(x, y, x + i, y + j));
		}
	}
	return ans;
}
int getans(int x, int y, int h, int w)
{
	int cnt = 0;
	for(int i=x;i<=h;i++)
		for (int j = y; j <= w; j++) {
			if (board[i][j] == 0)
				return 0;
			else
				cnt++;
		}
	return cnt;
}
void draw(int x, int y)
{
	for (int i = x; i < x + 10; i++)
		for (int j = y; j < y + 10; j++)
			board[i][j] = 1;
}