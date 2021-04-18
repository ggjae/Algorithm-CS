#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include <algorithm>
#include<memory.h>
using namespace std;

int map[51][51], map2[51][51];
int n, m, s, a, b, c;
int res = 2147000000;
vector<pair<pair<int, int>,int > > v;

int print_val() {
	int c_min = 2147000000;
	for (int i = 1; i <= n; i++) {
		int val = 0;
		for (int j = 1; j <= m; j++) {
			val += map[i][j];
 		}
 		if (c_min > val) c_min = val;
	}
 
	return c_min;
}

void turn_map(int x, int y, int t) {
    /*
	if (x - t<1 || y - t<1 || x + t> n || y + t > m) {
		return;
	}*/
	for (int ran = 1; ran <= t; ran++) {
		//맨 위 왼쪽 좌표
		int left_tmp = map[x - ran][y - ran];

		//좌 세로 
		for (int i = x - ran; i < x + ran; i++) {
			map[i][y - ran] = map[i+1][y - ran];
		}

		//밑 변하는 것 y
		for (int i = y-ran; i < y+ran; i++) {
			map[x + ran][i] = map[x + ran][i + 1];
		}

		//우 세로 변하는 것 x
		for (int i = x + ran; i > x-ran; i--) {
			map[i][y + ran] = map[i-1][y + ran];
		}

		//위쪽 변하는 것 y 
		for (int i = y + ran; i > y - ran; i--) {
			map[x-ran][i] = map[x-ran][i - 1];
		}

		map[x - ran][y - ran + 1] = left_tmp;
 
	}
}


int main() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map2[i][j] = map[i][j];
		}
	}

	for (int tt = 0; tt < s; tt++) {
		scanf("%d %d %d", &a, &b, &c);
 		v.push_back(make_pair(make_pair(a, b), c));
 	}

	sort(v.begin(), v.end());

	do {
 
		for (int i = 0; i < s; i++) {
			int aa = v[i].first.first;
			int bb = v[i].first.second;
			int cc = v[i].second;
 			if (aa - cc < 1 || bb - cc < 1 || aa + cc > n || bb + cc > m) continue;
			turn_map(v[i].first.first, v[i].first.second, v[i].second);
 		}

		int tmp = print_val();

		if (res > tmp) res = tmp;

		memset(map, 0, sizeof(map));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				map[i][j] = map2[i][j];
			}
		}
 
	} while (next_permutation(v.begin(), v.end()));

	printf("%d", res);
	return 0;
}