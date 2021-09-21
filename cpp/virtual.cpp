#include <iostream>
using namespace std;
class A 
{
public:
    void Show(){
        cout << "A show" << "\n";
    }
};
class B : public A
{
public:
    void Show(){
        cout << "B show" << "\n";
    }
};
class C : public B
{
public:
    void Show(){
        cout << "C show" << "\n";
    }
};

int main(){
    C * c = new C();
    B * b = c;
    A * a = b;

    a->Show();
    b->Show();
    c->Show();

    return 0;
}