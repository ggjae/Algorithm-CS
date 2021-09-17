#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{
    int idx;
    int weight;
    float winrate;
    int heavywincount;
} Boxer;
bool cmp(Boxer a, Boxer b){
    if(a.winrate > b.winrate) return true;
    if(a.winrate == b.winrate){
        if(a.heavywincount > b.heavywincount){
            return true;
        }
        if(a.heavywincount == b.heavywincount){
            if(a.weight > b.weight){
                return true;
            }
            if(a.weight == b.weight && a.idx < b.idx){
                return true;
            }
        }
    }
    return false;
}
vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<Boxer> boxers;
    for (int i = 0; i < head2head.size(); i++) { 
        int wins = 0; 
        float total = 0;
        int heavywin = 0; 
        for (int j = 0; j < head2head[i].length(); j++) { 
            
            if (head2head[i][j] == 'N') { 
                continue; 
            }
            
            if (head2head[i][j] == 'W') { 
                wins++; 

                if (weights[i] < weights[j]) {
                    heavywin++; 
                }
            }
            total++;  
        } 
        boxers.push_back({ i + 1, weights[i], total ? wins / total : 0, heavywin }); 
    }
    sort(boxers.begin(),boxers.end(), cmp);
    // 복서의 번호를 정렬
    for (Boxer boxer : boxers) { 
        answer.push_back(boxer.idx); 
    } 

    return answer;
}