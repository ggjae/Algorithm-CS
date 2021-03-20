#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int height[9];
    int sum = 0;
    for(int i=0;i<9;i++){
        cin >> height[i];
        sum += height[i];
    }
    int flag = 0;
    for(int i=0;i<9;i++){
        if(flag == 1) break;
        for(int j=i+1;j<9;j++){
            if(sum - (height[i] + height[j]) == 100){
                height[i] = -1;
                height[j] = -1;
                flag = 1;
                break;
            }
        }
    }
    sort(height,height+9);
    // int result =0;
    for(int i=2;i<9;i++){
        cout << height[i] << endl;
    }
    return 0;
}