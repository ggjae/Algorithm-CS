#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    // vector<pair<int, int> > s1;
    // for(int i=0;i<n;i++){
    //     s1.push_back({i,i+1}); // {0,1} , {1,2};
    // }
    vector<int> vs;
    vector<int> v;
    for(int i=0;i<n;i++){
        vs.push_back(i);
        v.push_back(i);
    }
    stack<int> d;
    for(int i=0;i<cmd.size();i++){
        for(int j=0;j<cmd[i].size();j++){
            // printf("k : %d cmd : %c\n",k,cmd[i][j]);
            if(cmd[i][j] == 'U'){
                int x = cmd[i][cmd[j].size()-1] - '0';
                int xcnt = 0;
                while(x != xcnt && k > 0){
                    k--;
                    if(vs[k] == -1){
                        continue;
                    } else {
                        xcnt++;
                    }
                }
                break;
            } else if(cmd[i][j] == 'D'){
                int x = cmd[i][cmd[j].size()-1] - '0';
                int xcnt = 0;
                while(x != xcnt && k < n){
                    k++;
                    if(vs[k] == -1){
                        continue;
                    } else{
                        xcnt++;
                    }
                }
                break;
            } else if(cmd[i][j] == 'C'){
                vs[k] = -1;
                d.push(k);
                int temp = k;
                while(vs[k] == -1 && k < n){
                    k++;
                    if(k == n){
                        k = temp;
                        break;
                    }
                }
                while(vs[k] == -1 && k > 0){
                    k--;
                }
                
            } else if(cmd[i][j] == 'Z'){
                int ne = d.top();
                d.pop();
                vs[ne] = ne;
            }
        }
    }

    for(int i=0;i<vs.size();i++){
        if(vs[i] != v[i]){
            answer.append("X");   
        } else {
            answer.append("O");
        }
    }
    return answer;
}
int main(){
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;
    cout << solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"}) << endl;
    cout << solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C","C","C","C","C"}) << endl;
    return 0;
}