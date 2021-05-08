#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    vector<int> chulCard, minCard, result;

    cin >> N >> M >> K;
    
    minCard.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> minCard[i];
    }

    chulCard.resize(K);
    for (int i = 0; i < K; ++i) {
        cin >> chulCard[i];
    }

    sort(minCard.begin(), minCard.end());

    // 이분탐색 후 선형탐색
    vector<bool> bChecked(M, false);
    result.resize(K);
    for (int i = 0; i < K; ++i) {
        int optimalIndex = M - 1;
        int card = chulCard[i];
        int l = 0;
        int r = M - 1;
        
        // 이분 탐색을 통해 처음 받은 카드 중 최적의 카드를 뽑음
        while (l <= r) {
            int mid = (l + r) / 2;

            if (minCard[mid] > card) {
                r = mid - 1;
                if (minCard[mid] < minCard[optimalIndex]) { optimalIndex = mid; }
            } else {
                l = mid + 1;
            }
        }

        // 최적 카드 값을 시작으로 뽑지 않은 카드를 탐색
        while (bChecked[optimalIndex] && optimalIndex < M) { ++optimalIndex; }
        bChecked[optimalIndex] = true;
        result[i] = minCard[optimalIndex];
    }


    for (int i = 0; i < K; ++i) {
        cout << result[i] << '\n';
    }
    return 0;
}
