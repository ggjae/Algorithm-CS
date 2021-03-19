#include <cstdio>
#include <algorithm>
using namespace std;
 
int main(){
    int N, arr[1000];
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", arr+i);
    
    int result = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(i!=j) result = max(result, arr[i]+arr[j]);
    printf("%d\n", result);
}
// 시간은 최대. 시간복잡도가 O(N^2)

#include <cstdio>
#include <algorithm>
using namespace std;
 
int main(){
    int N, arr[1000];
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", arr+i);
    sort(arr, arr+N);
    printf("%d\n", arr[N-1]+arr[N-2]);
}

// N이 1000을 넘어가면 N^2는 사용하면 안되니까.
// 1912, 2309, 2231, 3085, 10448, 2503, 1018, 1182