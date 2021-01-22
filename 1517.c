#include <stdio.h>

int A[500001];
int newA[500001];
int n;

long long int mergesort(int start, int end){
    
    if(start == end){
        return 0;
    }
    int mid = ( start + end ) / 2;
    long long int swapcount = mergesort(start, mid) + mergesort(mid+1, end);
    int i = start;
    int j = mid + 1;
    int k = 0;
    while(i<=mid || j <= end){
        if(i<=mid && (j>end || A[i]<=A[j])){
            newA[k++] = A[i++];
        } else {
            swapcount += (long long int)(mid - i + 1);
            newA[k++] = A[j++];
        }
    }
    for(int l= start; l<=end;l++){
        A[l] = newA[l-start];
    }
    return swapcount;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    long long int swapcount = mergesort(0,n-1);
    printf("%lld",swapcount);
    return 0;
}