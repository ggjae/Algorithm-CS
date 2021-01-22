#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int n,m,mid;
    int count = 1;
    int sumcount = 0;
    int start;
    int end;
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int *b = malloc(sizeof(int) * m);
    for(int i =0;i<m;i++){
        scanf("%d",&b[i]);
    }
    qsort(a, n, sizeof(int), compare);
    for(int i=0;i<m;i++){
        start = 0;
        end = n-sumcount;
        while (start <= end){
            mid = (start + end)/2;
            if (b[i] == a[mid]){ printf("1\n"); break;}
            else if(b[i] < a[mid]){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } if (start > end && i != m-1) {
            printf("0\n");
        } else if (start > end && i == m-1){
            printf("0\n");
        }
        
    }
    return 0;
}