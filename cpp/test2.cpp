#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    for(int i=0;i<num;i++){
        for(int j=num-1;j>i;j--){
            printf(" ");
        }
        for(int j=0;j<2*i+1;j++){
            printf("*");
        }
        printf("\n");
    }
  return 0;
}


