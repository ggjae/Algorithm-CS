#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int testa[5] = {1,2,3,4,5};
    int testb[8] = {2,1,2,3,2,4,2,5};
    int testc[10] = {3,3,1,1,2,2,4,4,5,5};

    int score[3] = {0, };
    int max_score = 0;
    for(int i=0;i<answers.size();i++){
        if(answers[i] == testa[i%5]){
            score[0]++;
        } if(answers[i] == testb[i%8]){
            score[1]++;
        } if(answers[i] == testc[i%10]){
            score[2]++;
        }
    }
    max_score = max(max(score[0],score[1]),score[2]);
    for(int i=0;i<3;i++){
        if(max_score == score[i]) answer.push_back(i+1);
    }
    return answer;
}