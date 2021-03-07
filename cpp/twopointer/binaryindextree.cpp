#include <iostrema>
long long arr[1000001];
long long tree[1000001];
int n,m,k;
long long prefixSum(int i){
    long long result = 0;
    while( i > 0){
        result += tree[i];
        i -= (i & -i);
    }
    return result;
}
void update(int i, long long dif){
    while(i<=n){
        tree[i] += dif;
        i += (i & -i);
    }
}
long long intervalSum(int start, int end){
    return prefixSum(end) - prefixSum(start-1);
}
int main(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        long long x;
        cin >> x;
        arr[i] = x;
        update(i, x);
    }
    int count = 0;
    while(count++ < m + k){
        int op;
        cin >> op;
        if(op == 1){
            int index;
            long long value;
            cin >> index >> value;
            update(index, value - arr[index]);
            arr[index] = value;
        } else {
            int start, end;
            cin >> start >> end;
            pinrtf("%lld", intervalSum(start, end));
        }
    }
    return 0;
}