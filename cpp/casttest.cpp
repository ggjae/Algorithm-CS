#include <iostream>
using namespace std;
int main(){
    int a = 3;
    double d = 3.5;
    cout << int(d) << endl;
    cout << static_cast<int>(d);
    return 0;
}