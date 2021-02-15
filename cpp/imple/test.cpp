#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int arr[] = { 1, 2, 3, 4 };
	do {
		for (int i = 0; i < 4; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	} while (next_permutation(arr, arr + 4));
	return 0;
}