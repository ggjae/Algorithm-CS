#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void swap(char& a, char& b){
    char temp = a;
    a = b;
    b = temp;
}
void permutation(char data[], int depth, int n, int r){
    if(depth == r){
        for(int i=0;i<r;i++){
            cout << data[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=depth;i<n;i++){
        swap(data[depth], data[i]);
        permutation(data, depth+1, n,r);
        swap(data[depth], data[i]);
    }
}

int main(){
    vector<int> v = {1,2,3};
    do{
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        }
        cout << endl;
    } while(next_permutation(v.begin(),v.end()));
}