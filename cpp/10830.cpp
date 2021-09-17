// 처음 생각, 행렬의 곱셈은 O(n^3)인데 슈트라센 알고리즘을 사용해야 그나마 O(n^2.81)정도로
// 최적화시킬 수 있다. 하지만 행렬의 곱셈이 아닌, **제곱**인점을 이용하여야 1000억번 곱하는
// 엄청난 시간복잡도에서 살아남을 수 있는 코드가 된다고 생각했다.
// 1000억번인데 시간제한이 1초이다. => log가 아니면 못살아 남을텐데...

// 그냥 값이라고 생각했을 때 제곱에서 최적화 시키는 방법이 뭐였지?
// 하고 떠올려보았다. => 제곱수가 짝수이면, 지수를 반으로 나눠서 그것을 제곱시키는 방향으로
// O(log n)의 복잡도를 가져갈 수 있겠다!

#include <iostream>
#include <vector>
using namespace std;
int num;
long long n;
long long a[6][6];
long long b[6][6];
long long ans[6][6];
void mul(long long a[6][6], long long b[6][6]){
    long long tmp[6][6] = {0};
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            for(int k=0;k<num;k++){
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] %= 1000;
            }
        }
    }

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            a[i][j] = tmp[i][j];
        }
    }
}
int main(){
    cin >> num >> n;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cin >> a[i][j];
        }
        ans[i][i] = 1;
    }
    while(n > 0){
        if(n % 2 == 1){
            mul(ans, a);
            n--;
        } else {
            mul(a, a);
            n /= 2;
        }
    }
    for(int i= 0;i<num;i++){
        for(int j=0;j<num;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


