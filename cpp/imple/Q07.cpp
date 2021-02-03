#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int suma = 0, sumb = 0;
    string score;
    cin >> score;
    int a = score.size()/2;
    for(int i=0;i<a;i++){
        suma += score[i] - '0';
    }for(int i=a;i<score.size();i++){
        sumb += score[i] - '0';
    }
    if(suma == sumb){
        cout << "LUCKY" << endl;
    } else {
        cout << "READY" << endl;
    }
    return 0;
}