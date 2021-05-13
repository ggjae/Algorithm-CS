#include <iostream>
#include <vector>
using namespace std;
int main(){
    int cnt[6] = {0, };
    auto a = {1,2,1,1,3,1,4,1,1,1,2,3,3,2,2,2,1,5,5,5,2,2,1,2,3,4,1,2,3,4,1,2};
    for(const auto& i : a){
        cnt[i]++;
    }
    for(int i=1;i<6;i++){
        while(--cnt[i] >= 0){
            printf("%d ",i);
        }
    }
    return 0;
}