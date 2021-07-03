#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
typedef pair<int, int> p;
 
int n, answer;
vector<string> dict;
 
class Trie {
private:
    Trie* childs[26];
    int child_cnt;
    bool isRoot, finish;
 
public:
    Trie(bool isroot) {
        for (int i = 0; i < 26; i++) childs[i] = NULL; 
        finish = false;
        isRoot = isroot;
        child_cnt = 0;
    }
 
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (childs[i] != NULL) delete childs[i];
    }
 
    void insert(const char* cur) {
        if (*cur == '\0') {
            finish = true;
            return;
        }
        int pos = *cur - 'a';
 
        if (childs[pos] == NULL) {
            childs[pos] = new Trie(false);
            child_cnt++;
        }
 
        childs[pos]->insert(cur + 1);
    }
 
    void find(const char* cur) {
        if (*cur == '\0') return;
        int pos = *cur - 'a';
 
        if (isRoot) answer++;
        else {
            if (child_cnt > 1) answer++;
            else if (finish) answer++;
        }
 
        childs[pos]->find(cur + 1);
    }
};
 
void init() {
    string input;
 
    dict.clear();
    for (int i = 0; i < n; i++) {
        cin >> input;
        dict.push_back(input);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
 
    while (cin >> n) {
        init();
        Trie root = Trie(true);
        for (int i = 0; i < dict.size(); i++) root.insert(dict[i].c_str());
 
        int total = 0;
        for (int i = 0; i < dict.size(); i++) {
            //cout << dict[i] << " : ";
            //printf("%d\n", root.find(dict[i].c_str(), 0));
            answer = 0;
            root.find(dict[i].c_str());
            total += answer;
        }
 
        double res = (double)total / n;
        printf("%.2lf\n", res);
    }
 
    return 0;
}