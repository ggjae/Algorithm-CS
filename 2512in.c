#include <stdio.h>

int main(){ // M값을 1부터 100000에서 이분탐색활용해볼 것
    int N;
    int M;
    int state[10001];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&state[i]);
    }
    scanf("%d",&M);
    int low = 1, high = 200000;
    int sum;
    while(low + 1 < high){
        int mid = (low+high) / 2;
        sum = 0;
        for(int i =0;i<N;i++){
            if(state[i] <= mid){
                sum += state[i];
            } else {
                sum += mid;
            }
        }
        if(sum <= M){
            low = mid;
        } else {
            high = mid;
        }
    }
    for(int i=0;i<N;i++){
        if(state[i] > low){
            state[i] = low;
        }
    }
    int answer = state[0];
    for(int i=0;i<N;i++){
        if(answer < state[i]){
            answer = state[i];
        }
    }
    printf("%d",answer);
    //상한액을 잡아야함.
}