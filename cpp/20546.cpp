#include <iostream>
#include <vector>
using namespace std;
int main(){
    int cash;
    int p[14];
    int junhyeoncash = 0;
    int junhyeonjusik = 0;
    int seongmincash = 0;
    int seongminjusik = 0;
    int count = 0;
    cin >> cash;
    junhyeoncash = cash;
    seongmincash = cash;
    for(int i=0;i<14;i++){
        cin >> p[i];
        if(p[i] <= junhyeoncash){
            junhyeonjusik = junhyeoncash/p[i];
            junhyeoncash %= p[i];
        }
        if(i >= 3){
            if(p[i] < p[i-1]){
                if(p[i-1] < p[i-2]){
                    if(p[i-2] < p[i-3]){
                        if(p[i] <= seongmincash){
                            seongminjusik += seongmincash/p[i];
                            seongmincash %= p[i];
                        }
                        
                    }
                }
            } else if(p[i] > p[i-1]){
                if(p[i-1] > p[i-2]){
                    if(p[i-2] > p[i-3]){
                        if(seongminjusik > 0) {
                            seongmincash += seongminjusik*p[i];
                            seongminjusik = 0;
                        }
                    }
                }
            }
        }
    }
    seongmincash = seongmincash + seongminjusik * p[13];
    junhyeoncash = junhyeoncash + junhyeonjusik * p[13];
    if(seongmincash > junhyeoncash) printf("TIMING");
    else if (seongmincash == junhyeoncash) printf("SAMESAME");
    else printf("BNP");
    return 0;
}