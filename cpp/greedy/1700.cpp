#include <iostream>
 
using namespace std;
 
int N, K;
int order[101];
int hole[101];
int result;
 
int main()
{
    cin >> N >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> order[i];
    }
 
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // 구멍이 비어 있는 경우
            if (!hole[j])
            {
                hole[j] = order[i];
                break;
            }
            else
            {
                // 이미 사용중이면 넘어간다
                if (order[i] == hole[j])
                {
                    break;
                }
                // 다음 구멍을 검사한다
                if (j != N) continue;
 
                // 멀티탭에 꽃혀 있는 것 중에서 가장 나중에 사용하는 것을 고른다.
                int change, val = -1;
                for (int k = 1; k <= N; k++)
                {
                    int term = 0;
                    for (int l = i + 1; l <= K && order[l] != hole[k]; l++) term++;
                    if (term > val)
                    {
                        val = term;
                        change = k;
                    }
                }
                // 가장 나중에 사용하는 것을 뽑는다.
                hole[change] = order[i];
                result++;
            }
        }
    }
 
    cout << result;
 
    return 0;
}