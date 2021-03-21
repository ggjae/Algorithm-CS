#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    int k[1001];
    int samgaksu[50];
    int sum[200000];
    cin >> t;
    for(int i=1;i<50;i++){
        samgaksu[i] = (i * (i+1)) / 2;
    }
    int idx = 0;
    for(int i=1;i<50;i++){
        for(int j=1;j<50;j++){
            for(int k=1;k<50;k++){
                sum[idx++] = samgaksu[i]+samgaksu[j]+samgaksu[k];
            }
        }
    }
    for(int i=0;i<t;i++){
        int flag = 0;
        cin >> k[i];
        for(int j=0;j<50*50*50;j++){
            if(k[i] == sum[j]){
                flag = 1;
                printf("1\n");
                break;
            }
        }
        if(flag == 0){
            printf("0\n");
        }
    }
    
    
    return 0;
}