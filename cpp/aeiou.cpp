#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<string> v = {"A","E","I","O","U"};
set<string> s;

// makeword를 통해 string을 만듬
// A, E, I, O, U가 sol에서 작동하고, 재귀방식으로 진행됨
// "사전에서" 첫번째 단어가 A, 마지막 단어가 UUUUU => set을 쓰면 자동 정렬
// idx는 0부터 시작하지만, 사전에선 1번째부터이므로 ans = idx + 1

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