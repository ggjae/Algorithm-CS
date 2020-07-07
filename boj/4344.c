#include <stdio.h>
int main(){
    int a,b;
    int c[1001];
    int sum;
    int ave;
    int count = 0;
    float ratio;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&b);
        sum = 0;
        count = 0;
        for(int j=0;j<b;j++){
            scanf("%d",&c[j]);
            sum += c[j];
        }
        ave = sum / b;
        for(int k=0;k<b;k++){
            if(ave<c[k]){
                count++;
            }
        }
        
        ratio = (float) count/(float) b * 100;
        printf("%.3f%%\n",ratio);
    }
    return 0;
}