#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int down[500001];
int up[500001];
vector<int> v;

int main() {
	int num, height, val;
	cin >> num >> height;
	for (int i = 0; i < num; i++) {
		cin >> val;
		if (i % 2 == 0) down[val]++;
		else up[val]++;		
	}
	for (int i = height-1; i >= 1; i--) {
		down[i] += down[i + 1];
		up[i] += up[i + 1];
	}
	for (int i = 1; i <= height; i++)
		v.push_back(down[i] + up[height - i + 1]);

	sort(v.begin(),v.end());

	int ans = 1;
	int result = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == result) ans++;	
		else break;
	}
	cout << result << " " << ans;
	return 0;
}