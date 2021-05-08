#include <string>
#include <vector>
#include <set>
using namespace std;

int Rank(int num){
    if(num == 1 || num == 0) return 6;
    else return 7 - num;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> win_num;
    for(int i = 0; i < 6; ++i)
        win_num.insert(win_nums[i]);

    int illegible = 0; // 알아볼 수 없는 숫자의 수
    int same = 0;      // 로또 번호와 일치하는 수
    for(int i = 0; i < 6; ++i){
        if (lottos[i] == 0)
            illegible++;
        else if (win_num.find(lottos[i]) != win_num.end())
            same++;
    }
    
    answer.push_back(Rank(same + illegible)); // 최고 순위는 알아 볼 수 없는 숫자가 모두 로또 번호와 일치했을 때
    answer.push_back(Rank(same)); // 최저 순위는 알아 볼 수 없는 숫자가 모두 맞지 않았을 때
    return answer;
}