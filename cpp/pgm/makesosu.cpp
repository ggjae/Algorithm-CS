#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
bool check(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}
int solution(vector<int> nums) {
    int answer = 0;
    // vector<bool> visited(50000, false);
    for(int i=1;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                if(i != j && j != k && i != k){
                    int sum = i+j+k;
                    if(check(sum)){
                        printf("%d %d %d %d\n",a,b,c,sum);
                        answer++;
                    }
                    
                }
            }
        }
    }

    return answer;
}