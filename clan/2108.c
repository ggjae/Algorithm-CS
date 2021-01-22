#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

float a[500001];
int b[500001][2];
int main(){
    int flag = 0;
    int n,tmp;
    int maxval = -4001;
    int minval = 4001;
    int max = -4001;
    int count = 0;
    int sumb = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%f",&a[i]);
        b[i][0] = a[i];
        b[i][1] = 1;
        sumb += a[i];
        if(minval > b[i][0]){
            minval = b[i][0];
        }
        if(maxval < b[i][0]){
            maxval = b[i][0];
        }
        if(i>0 && b[i][0] == b[i-1][0]){
            count++;
            b[i][1] = count;
        } else {
            count = 0;
        }
    }
    // count = 0;
    // for(int i =0;i<n;i++){
    //     if(max<b[i][1]){
    //         max = b[i][1]; // max에는 1이 들가겟제 ?
    //         tmp = i; // tmp에는 0이 드러갈것이여. 그 다음 포문 보자.
    //     } else if(max == b[i][1]){
    //         if(b[i][1] != 1){
    //             tmp = i;
    //             count++;
    //         }else if(count == 1){
    //             tmp = i;
    //         }
    //     }
    // }
    qsort(a,n,sizeof(float),compare);
    count = 0;
    for(int i=0;i<n;i++){
        if(a[i] == a[i+1]){
            count++;
            tmp = i;
        } 
    }

    if(((double)sumb/(double)n) > -1&&(double)sumb/(double)n<0) {
        printf("0\n");
    }
    else printf("%1.f\n",(double)sumb/(double)n);
    
    float ab = (double)n/2 - 0.5;
    printf("%d\n",a[(int)ab]);
    printf("%d\n",b[tmp][0]);
    printf("%d",maxval-minval);
    return 0;
}