#include <iostream>

using namespace std;

int main() {
    int input;
    int coin[4] = {0, 0, 0, 0};
    cin >> input;
    int temp = 1000 - input;
    while(temp>0){
        if(temp>500){
            coin[0] += temp/500;
            temp = temp%500;
        } else if(temp>100){
            coin[1] += temp/100;
            temp = temp%100;
        } else if(temp>50){
            coin[2] += temp/50;
            temp = temp%50;
        } else {
            coin[3] += temp/10;
            temp = temp%10;
        }
    }
    for(int i=0;i<4;i++){
        cout << coin[i] << ' ';
    }
  return 0;
}
