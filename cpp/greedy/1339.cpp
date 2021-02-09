#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int alphabet[26];
vector<string> v;
bool cmp(int A, int B)
{
    if (A > B) return true;
    return false;
}
int main(){
    int n;
    cin >> n;
    int a;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        string tmp = v[i];
        int len = tmp.length();
        int pow = 1;
        for(int j=len-1;j>=0;j--){
            int tr = tmp[j] - 'A';
            // printf("%d",tr);
            alphabet[tr] = alphabet[tr] + pow;
            // printf("alpha : %d",alphabet[tr]);
            pow = pow * 10;
        }
    }
    sort(alphabet,alphabet+26,cmp);
    int answer = 0;
    int num = 9;
    for(int i=0;i<26;i++){
        if(alphabet[i] == 0) break;
        answer = answer + (alphabet[i] * num);
        num--;
    }
    cout << answer;
    return 0;
}