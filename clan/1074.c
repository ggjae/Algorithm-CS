#include <stdio.h>
int r;
int c;
int count = 0;
int flag = 0;
void recur(int N,int y,int x){ // r은 3, c는 1
    if(N == 2){
        if(y == r && x == c){
            printf("%d\n",count);
        } else if(y == r && x+1 == c){
            printf("%d\n",count+1);
        }else if(y+1 == r && x == c){
            printf("%d\n",count+2);
        }else if(y+1 == r && x+1 == c){
            printf("%d\n",count+3);
        } else {
            printf("병신");
        }
    } else{
        if(y <= r && r < y+N/2 && c >= x && x+N/2 > c){
            recur(N/2,y,x);
        } else if(y <= r && r < y+N/2 && c >= x+N/2 && x+N > c){
            count += N/2*N/2;
            recur(N/2,y,x+N/2);
        } else if(r < y+N && r >= y+N/2 && c >= x && x+N/2 > c){
            count += N/2*N/2*2;
            recur(N/2,y+N/2,x);
        } else{
            count += N/2*N/2*3;
            recur(N/2,y+N/2,x+N/2);
        }
    }
    

}
int main(){
    int N;
    int num = 1;
    scanf("%d %d %d", &N,&r,&c);
    for(int i=0;i<N;i++){
        num *= 2;
    }
    recur(num,0,0);
}