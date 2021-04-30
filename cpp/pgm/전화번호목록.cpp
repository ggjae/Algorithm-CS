#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> um;
    for(int i=0;i<phone_book.size();i++){
        string str = "";
        for(int j=0;j<phone_book[i].size();j++){
            str += phone_book[i][j];
            um[str]++;
        }
    }
    for(int i=0;i<phone_book.size();i++){
        if(um[phone_book[i]] > 1){
            answer = false;
            break;
        }
    }
    
    return answer;
}