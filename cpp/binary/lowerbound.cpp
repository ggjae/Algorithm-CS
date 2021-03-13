#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int arr[6] = { 1,2,3,4,5,6 };
	cout << "lower_bound(6) : " << lower_bound(arr, arr + 6, 6) - arr;
    // arr부터 끝까지 탐색하며 6이상의 숫자가 처음으로 나오는 위치의
    // 뒤의 arr을 빼주는 이유는, 반한형이 iterator이므로 첫번째 주소를 뺴는것이라고 생각
    // 결과 -> lower_bound(6) : 5
    // 로워바운드는 이상이고

    vector<int> arr = { 1,2,3,4,5,6 };
	cout << "upper_bound(3) : " << upper_bound(arr.begin(), arr.end(), 3) - arr.begin();
    // 어퍼바운드는 초과
    // 결과 -> upper_bound(3) : 3
	return 0;
}