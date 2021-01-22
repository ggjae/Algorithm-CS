#include <stdio.h>
int main(){
    int A[50001];
    int n;
    int ballcount = 0;
    int point = 0;
    int base[3] = {0, 0, 0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++){
        if(ballcount == 4 || A[i] == 2){
            ballcount = 0;
            base[0] = 1;
            if(base[2] == 1){
                if(base[1] == 1 && base[0] == 1){
                    point++;
                } else {
                    continue;
                }
            } else if(base[1] == 1){
                if(base[0] == 1){
                    base[2] = 1;
                }
            }
        } else {
            if(A[i] == 3){
                ballcount++;
                if(base[2] == 1){
                    point++;
                    base[2] = 0;
                } if(base[1] == 1){
                    base[2] = 1;
                    base[1] = 0;
                } if(base[0] == 1){
                    base[1] = 1;
                    base[0] = 0;
                }
            }
            else if(A[i] == 1){
                ballcount++;
            }
        }
    }
    printf("%d",point);
}