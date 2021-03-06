#include <iostream>
#include <vector>
using namespace std;
int main(){
    string a;
    cin >> a;
    int suma = 0;
    int sumb = 0;
    for(int i=0;i<a.size();i++){
        if(i<a.size()/2){
            suma += a[i]-'0';
        } else {
            sumb += a[i]-'0';
        }
    }
    if(suma == sumb) printf("LUCKY");
    else printf("READY");
    return 0;
}