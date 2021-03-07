#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string a;
    cin >> a;
    vector<char> ch;
    int suma = 0;
    for(int i=0;i<a.size();i++){
        if('A' <= a[i] && a[i] <= 'Z'){
            ch.push_back(a[i]);
        } else{
            suma += a[i] - '0';
        }
    }
    sort(ch.begin(),ch.end());
    for(int i=0;i<ch.size();i++){
        printf("%c",ch[i]);
    }
    printf("%d\n",suma);
    
    return 0;
}