#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstring>
using namespace std;
int solution(string dartResult) {
    int answer = 0;
    int gab[3];
    int idx = 0;
    int j =0;
    memset(gab, 0, sizeof(gab));
    for(int i=0;i<dartResult.size();i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(dartResult[i+1] == '0'){
                gab[j] = 10;
            } else {
                gab[j] = dartResult[i] - '0';
            }
            j++;
        }
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            if(dartResult[i] == 'D'){
                gab[j-1] = pow(gab[j-1],2);
            } else if(dartResult[i] == 'T'){
                gab[j-1] = pow(gab[j-1],3);
            }
        } else if(dartResult[i] == '*' || dartResult[i] == '#'){
            if(dartResult[i] == '*') {
                if(j == 1){
                    gab[j-1] = gab[j-1] * 2; 
                } else {
                    gab[j-2] = gab[j-2] * 2;
                    gab[j-1] = gab[j-1] * 2;
                }
            } else {
                gab[j-1] = -gab[j-1];
            }
        }

    }
    for(int i=0;i<3;i++){
        answer += gab[i];
    }
    return answer;
}
int main(){
    printf("%d",solution("1S2D*3T"));
    return 0;
}