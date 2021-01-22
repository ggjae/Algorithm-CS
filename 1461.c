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
int main(){
    int n,m;
    int j = 0; // positive index
    int k = 0; // negative index
    int tmp;
    int cnt = 0;
    int positive[10001];
    int negative[10001];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        if(tmp > 0){
            positive[j++] = tmp;
        } else {
            negative[k++] = abs(tmp);
        }
    }
    if(j != 0 && k != 0){
        qsort(positive,j,sizeof(int),compare);
        qsort(negative,k,sizeof(int),compare);
        if(positive[j-1]>negative[k-1]){
            cnt += positive[j-1];
            j = j-1;
            for(int i = m-1;i<=k;i+=m){
                cnt += negative[i] * 2;
            }
            for (int i = m-1;i<=j;i+=m){
                cnt += positive[i] * 2;
            }
        } else {
            cnt += negative[k-1];
            k = k-1;
            for(int i=m-1;i<=j;i+=m){
                cnt += positive[i] * 2;
            }
            for(int i=m-1;i<k;i+=m){
                cnt += negative[i] * 2;
            }
            
        }
    }
    else if(j==0){
        qsort(negative,k,sizeof(int),compare);
        cnt += negative[k-1];
        k = k-1;
        if(k == m-1){
            printf("%d",cnt);
            return 0;
        }
        for(int i=m-1;i<=k;i+=m){
            cnt += negative[i] * 2;
        }
    } else if(k==0){
        qsort(positive,j,sizeof(int),compare);
        cnt += positive[j-1];
        j = j-1;
        if(j == m-1){
            printf("%d",cnt);
            return 0;
        }
        for (int i = m-1;i<=j;i+=m){
            cnt += positive[i] * 2;
        }
    } else {
        printf("씨발");
    }
    printf("%d",cnt);
}