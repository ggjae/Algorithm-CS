#include <iostream>
#include <vector>
using namespace std;
int main(){
    int x = 1;
    int y = 6;
    while(y--){
        x++;
    }
    printf("x %d y %d",x,y);
    return 0;
}