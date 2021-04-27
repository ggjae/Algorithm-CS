#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count = 0;
    int zerocount = 0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(win_nums[i] == lottos[j]){
                count++;
            }
        }
    }
    for(int i=0;i<6;i++){
        if(lottos[i] == 0){
            zerocount++;
        }
    }
    if(count <= 1){
        answer.push_back(6);
    } else{
        answer.push_back(7-count);
    }
    sort(answer.begin(),answer.end());
    return answer;
}