#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<string> v = {"A","E","I","O","U"};
set<string> s;

void makeword(string cur) {
    if(cur.size()>5) return;
    s.insert(cur);
    for(int i = 0; i < 5; i++) makeword(cur+v[i]);
}
int solution(string word) {
    int answer = 0;
    for(int i = 0; i < 5; i++) makeword(v[i]);
    int idx=0;

    for(auto it = s.begin(); it != s.end(); it++, idx++) {
        cout << *it << "\n";
        if(*it == word){ 
            answer = idx+1; 
            break; 
        } 
    }
    return answer;
} 

int main(){
    cout << solution("AAEAE");
    return 0;
}