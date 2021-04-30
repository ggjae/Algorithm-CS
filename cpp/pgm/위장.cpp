#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    unordered_map<string, bool> mb;
    for(int i=0;i<clothes.size();i++){
        um[clothes[i][1]]++;
        mb[clothes[i][1]] = false;
    }
    for(int i=0;i<clothes.size();i++){
        if(mb[clothes[i][1]] == true){
            continue;
        } else {
            answer *= (um[clothes[i][1]]+1); 
            mb[clothes[i][1]] = true;
        }
    }
    return answer-1;
}