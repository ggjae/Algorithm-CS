#include <iostream>
#include <vector>
using namespace std;
int main(){
    int burger[3];
    int cola;
    int cider;
    int m = 2001;
    for(int i=0;i<3;i++){
        cin >> burger[i];
        if(m > burger[i]) m = burger[i];
    }
    cin >> cola;
    cin >> cider;
    if(cola > cider) printf("%d", m+cider-50);
    else printf("%d", m+cola-50);
    return 0;
}