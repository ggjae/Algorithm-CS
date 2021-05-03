#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<string, int> um;
    um["a"] = 1;
    um["b"] = 5;
    um["c"] = 6;
    um["e"] = 7;
    um["f"] = 8;
    um["a"] = 3;
    for(auto a : um){
        cout << a.first << "이" << a.second << endl;
    }
    return 0;
}