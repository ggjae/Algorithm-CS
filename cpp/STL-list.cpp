#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> lst;
    lst.push_back(10);
    lst.push_front(20);
    lst.push_back(40);
    lst.push_front(30);
    for(const auto& a : lst){
        printf("%d",a);
    }
    for(auto itr = lst.begin();itr != lst.end();itr++){
        if(*itr == 20){
            lst.insert(itr,50);
        }
    }
    printf("\n");
    for(const auto& a : lst){
        printf("%d",a);
    }
    return 0;
}