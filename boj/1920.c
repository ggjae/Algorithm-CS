#include <stdio.h>
void quick_sort(int *data, int start, int end){
    if(start >= end){ // 원소가 1개인 경우 
    return; 
    } 
    int pivot = start; 
    int i = pivot + 1; // 왼쪽 출발 지점 
    int j = end; // 오른쪽 출발 지점 
    int temp; 
    while(i <= j){ // 포인터가 엇갈릴때까지 반복 
        while(i <= end && data[i] <= data[pivot]){
            i++; 
        } while(j > start && data[j] >= data[pivot]){
            j--;
        } 
        if(i > j){// 엇갈림 
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }else{ // i번째와 j번째를 스왑
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        } 
    } // 분할 계산 
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end); 
}
int main(){
    int acount[100001];
    int bcount[100001];
    int a,b,k;
    int startindex,endindex;
    scanf("%d",&a);
    for(k=0;k<a;k++){
        scanf("%d",&acount[k]);
        printf("acount[%d] = %d\n",k,acount[k]);
    } // a번 만큼 입력받고
    scanf("%d",&b);
    for(k=0;k<b;k++){
        scanf("%d",&bcount[k]);
        printf("bcount[%d] = %d\n",k,bcount[k]);
    } // b번 만큼 입력 바다
    printf("%d",bcount[b-1]);
    // quick_sort(acount,0,a-1); // a번 받은거 소팅
    startindex = 0;
    printf("너뭐해??%d",startindex);
    endindex = a-1; // acount를 소팅한것에서 찾을거야.
    int mid;
    for(k=0;k<b;k++){
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