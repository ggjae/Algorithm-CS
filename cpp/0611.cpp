#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 오늘 들을 강의, kotlin, 벡터.

// bool compare(vector<pair<int, string> > a,vector<pair<int, string> > b){
//     if(a.second > b.second) return false;
//     else return true;
// }

// 시간초과를 안당하려면, ex) 데이터 백만개 필요하다
// 사이즈를 고정시키면 푸시백으로 못넣는다..!
// 
int main(){
    int n=0;
    string a;
    int b; 
    vector<pair<int, string> > student; // 뒤에 꺽쇄 겹치는거 한칸 띄워줘야하는데 보기싫어서 typedef
    // 받을때마다 사이즈를 할당하기때문에 받을때마다 시간이 조금 더 소요된다..
    // pair<int, string> student[100001];
    // 희선생의 의견 : 페어는 앞부분에 주로 비교할 것을 넣는다...
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        student.push_back(make_pair(b,a));
        // n개만큼 벡터가 들어간 것.
    }
    sort(student.begin(),student.end(),greater<>()); // sort를 벡터로도 사용 가능하지.
    for(int i=0;i<n;i++){
        cout << student[i].second << " ";
    }
    cout << endl;
    return 0;
}

C++ vs JAVA
나 앱개발 하고싶어...
C++ 