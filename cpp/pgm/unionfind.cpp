#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int getParent(int set[], int x){
    if(set[x] == x) return x;
    return set[x] = getParent(set,set[x]);
}
void unionParent(int set[], int a, int b){
    a = getParent(set, a);
    b = getParent(set, b);
    if(a < b) set[b] = a;
    else set[a] = b; 
}
int find(int set[], int a, int b){
    a = getParent(set,a);
    b = getParent(set,b);
    if(a == b) return 1;
    else return 0;
}
int main(){
    // 정렬
    
    return 0;
}