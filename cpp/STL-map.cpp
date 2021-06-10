#include <iostream>
#include <map>
using namespace std;
int main(){

    // map은 index로 int가 아닌 다른 자료형을 사용할 수 있는 배열
    // map은 트리구조입니다. index가 중복될 수 없다.
    // map은 iterator를 많이 쓴다... key와 벨류의 쌍임.
    // set은 key만 있는 map . set도 정렬되어 있습니다.
    // set은 key와 value가 같은 데이터 원소로 저장한다고 생각하면 좋겠다.
    map<int, string> m; // 선언할 때 잘 해주면 된다 !!!

    m.insert({1, "첫번째 방법"});
    m.insert({2, "두번째 방법"});
    m.insert({3, "세번째 방법"});
    m.erase(2);
    for(const auto& a : m){
        cout << a.first << " " << a.second;
    }

    // 검색에 강한 map, set !
    return 0;
}