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
int c[500000][2];
int main(){
    int n,m,mid;
    int count = 1;
    int sumcount = 0;
    int start = 0;
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
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            count++;
            sumcount++;
            printf("abcabcabcabc i : %d a[i] : %d sumcount : %d count : %d\n",i,a[i],sumcount,count);
        } else {
            c[i-sumcount][0] = a[i];
            c[i-sumcount][1] = count; // 값을 바꿔줌.
            count = 1;
            printf("defdefdfedf i : %d a[i] : %d sumcount : %d count : %d\n",i,a[i],sumcount,count);
        }
    }
    int end = n-sumcount;
    for(int i=0;i<m;i++){
        start = 0;
        end = n-sumcount;
        while (start <= end){
            mid = (start + end)/2;
            if (b[i] == c[mid][0]){ printf("%d ", c[mid][1]); break;}
            else if(b[i] < c[mid][0]){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } if (start > end && i != m-1) {
            printf("0 ");
        } else if (start > end && i == m-1){
            printf("0");
        }
        
    }
    return 0;
}