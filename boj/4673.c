#include <stdio.h>

int a[10000];
int d(int n)
{
	int t = n;
	while (n > 0) {
		t += n % 10;
		n /= 10;
	}
	if (t > 10000) return 0;
	a[t - 1] = 0;
	d(t);
}

int main()
{
	for (int i = 1; i <= 10000; i++) a[i - 1] = i;

	while (1) {
		for (int i = 0; ; i++) {
			if (i == 10000) return 0;
			else if (!a[i]) continue;
			else printf("%d\n", i + 1);
			a[i] = 0;
			d(i + 1);
		}
	}
	return 0;
}