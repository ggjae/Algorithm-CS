#include <iostream>
using namespace std;
void A(int number){
    cout << "Hello" << number << "\n";
}
void B(void (*ptr) (int)){
    ptr(2002);
}
int main(){
    void (*p)(int) = &A;
    B(p);
    return 0;
}
