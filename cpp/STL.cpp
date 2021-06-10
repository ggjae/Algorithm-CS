#include <iostream>
#include <vector>
using namespace std;

int main(){
//  STL

// => Sequence Container (객체를 순차적으로 보관) - 순서 컨테이너
// array, vector, deque, list
// => Associative Container (키를 바탕으로 대응되는 값) - 연관 컨테이너
// set, map, multiset, multimap
// map 이 python의 dictionary. { key = {string 이여도 됨}, value }
// set은 key가 sort 되어 있음. ?

// 시퀀스 컨테이너 - 벡터, 리스트, 덱
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(40);
    vec.push_back(30);
    for(auto a : vec){
        printf("%d",a);
    }
    // 반복자 iterator vec.begin(), vec.end() => begin은 들어가있는 칸
    // end는 없는 칸.. 아무것도 들어있지 않은 칸
    auto itr = vec.begin() + 2; // iterator에 * 을 씀으로 써 값에 접근 가능
    printf(" *********** %d", *itr);

    vec.insert(vec.begin()+2, 15);
    // insert(iterator, 값);
    vec.erase(vec.begin()+3);
    // erase => iterator 위치
    vector<int>::iterator itr2 = vec.begin();
    for(;itr2 != vec.end();++itr2){
        if(*itr2 == 20){
            vec.erase(itr2);
        }
    }

    for(auto a : vec){
        printf("%d",a);
    }
    printf("test\n");
    for(const auto& a : vec){
        printf("%d",a);
    }
    
    return 0;
}