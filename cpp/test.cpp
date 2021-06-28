#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a(5,0);
    for(int i=0;i<a.size();i++){
        a[i] = i;
        printf("%d",a[i]);
    }
    return 0;
}