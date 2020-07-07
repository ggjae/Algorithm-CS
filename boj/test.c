#include <stdio.h>
int main(){
    int acount[100001];
    int bcount[100001];
    int a,b,k;
    int startindex,endindex;
    scanf("%d",&a);
    for(k=0;k<a;k++){
        scanf("%d",&acount[k]);
    } // a번 만큼 입력받고
    scanf("%d",&b);
    for(k=0;k<b;k++){
        scanf("%d",&bcount[k]);
    } // b번 만큼 입력 바다
    // quick_sort(acount,0,a-1); // a번 받은거 소팅
    startindex = 0;
    printf("너뭐해??%d",startindex);
    endindex = a-1; // acount를 소팅한것에서 찾을거야.
    int mid;
    for(k=0;k<b;k++){
        printf("뭐해");
        while(1){
            mid = (startindex + endindex) / 2;
            if(acount[mid] < bcount[k]){
                startindex = mid + 1;
            } else if (acount[mid] > bcount[k]){
                endindex = mid - 1;
            } else if (acount[mid] == bcount[k]) {
                printf("1");
                break;
            } else {
                printf("0");
                break;
            }
        }
    }
    return 0;
}