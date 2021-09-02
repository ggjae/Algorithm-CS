#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int i = 0;
    for(int s=2; s <= n; i++)
        s += 6*i;
    if(n == 1) i=1;
    cout << i;
    return 0;
}