#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <set>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    set<int> s;
    stack<int> st;
    for(int i=0;i<n;i++) s.insert(i);
    auto it = s.find(k);
    for (const auto &str : cmd){
        if(str == "C"){
            auto nxt = next(it);
            st.push(*it);
            s.erase(it);
            it = nxt;
            printf("%d\n",*s.end());
            if(it == s.end()) --it;
        } else if (str == "Z"){
            int top = st.top();
            st.pop();
            s.insert(top);
        } else {
            int d = stoi(str.substr(2));
            if(str[0] == 'U') d *= -1;
            it = next(it,d);
        }
    }
    string ans(n, 'X');
    for (const auto &i : s) ans[i] = 'O'; // set에 있는 것들 하나씩 i에 넣는 느낌.
    return ans;
}
int main(){
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;
    cout << solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"}) << endl;
    cout << solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C","C","C","C","C","C"}) << endl;
    return 0;
}