#include <iostream>
#include <vector>
using namespace std;
vector<char> k;
char tmp[200];
vector<pair<char, char> > pv;
int n;
bool visited[52];
string line;
int main(){
    getline(cin, line);
    for(int i=0;i<line.size();i++){
        if(line[i] = ' ') continue;
        k.push_back(line[i]);
    }
    cin >> n;
    for(int i=0;i<n;i++){
        char tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        pv.push_back(make_pair(tmp1,tmp2));
    }
    for(int i=0;i<n;i++){
        bfs(pv[i].first,pv[i].second,i);
// h g 들어가면 h 출력하고, 1부터 g와 같은게 잇는지 보다 gr 만나면
// g 출력하고, 마지막에
        printf("\n");
    }
    return 0;
}