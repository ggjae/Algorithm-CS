#include <stdio.h>
#include <stdlib.h>

#define size 10000

int main() {
	int n, input;
	scanf("%d", &n);

	int arr[size] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		arr[input - 1]++;
	}

	for (int i = 0; i < size; i++) {
		for (int k = 0; k < arr[i]; k++) {
			printf("%d\n", i + 1);
		}
	}
	return 0;
}