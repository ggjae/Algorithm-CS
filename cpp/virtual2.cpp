#include <iostream>
class Animal
{
public:
    virtual void speak(){
        std::cout << "Animal" << std::endl;
    }
    virtual ~Animal()=default;
};
class Cat : public Animal
{
public:
    void speak() override
    {
        std::cout << "Meow~" << std::endl;
    }
};

int main(){
    int i =0;
    std::cin >> i;
    // dynamic polymorphism
    Animal * polyAnimal;
    if( i == 1){
        polyAnimal = new Cat();
    } else {
        polyAnimal = new Animal();
    }
    polyAnimal->speak();
    return 0;
}
// 가상함수. C++ 컴파일러는 일반적으로 선언해준 타입에 따라서 작동을 함.
// 그래서 virtual.cpp에서는 분명 다 같은 객체 C를 가리키고 있음에도
// 다르게 행동하였는데, 다이나믹 폴리몰피즘을 이용하기 위하여
// virtual 함수를 사용합니다. 런타임시에 새로 할당해준 객체에 대하여
// 올바른 메소드를 실행시키기 위해서.