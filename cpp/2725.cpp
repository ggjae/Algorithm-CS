#include<iostream>

using namespace std;

int arr[1001];

int gcd(int a, int b) {
	int t;
	while (b) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
	int c;
	cin >> c;
	arr[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1)
				cnt++;
		}
		arr[i] = arr[i - 1] + 2 * cnt;
	}
	while (c--) {
		int n;
        cin >> n;
		printf("%d\n", arr[n]);
	}
	return 0;
}