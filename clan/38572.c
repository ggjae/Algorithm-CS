#include <stdio.h>

int main() {
	long long arr[10] = { 0 };
	long long arr2[10] = { 0 };
	int n;
	long long a = 0;
    scanf("%d",&n);
	for (int i = 1; i < 10; i++) {
		arr[i] = 1;
	}

	for (int i = 0; i < n-1; i++) {
		for (int i = 0; i < 10; i++) {
			if (i == 0) {
				arr2[i] = arr[i + 1];
			}
			else if (i == 9) {
				arr2[i] = arr[i - 1];
			}
			else {
				arr2[i] = (arr[i - 1] + arr[i + 1]) % 1000000000
			}
		}
		for (int i = 0; i < 10; i++) {
			arr[i] = arr2[i];
		}
	}

	for (int i = 0; i < 10; i++) {
		a = (a + arr[i])%1000000000;
	}

	printf("%d",a%1000000000);

	return 0;
}